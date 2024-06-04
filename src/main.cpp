#include <carrinho.hpp>
#include <WiFi.h>
#include <PubSubClient.h>

Carrinho c;

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Payload recebido: ");
    Serial.println(*payload);
    if (strcmp(topic, "carrinho/controle/velocidade_max"))
    {
        short v = *payload;
        c.setVelocidadeMax(v);
    }
    if (strcmp(topic, "carrinho/controle/direcao_e_parada"))
    {
        c.setComando((char)*payload);
    }
}

void reconnect()
{   static unsigned long antes = millis();
    if (!client.connected())
    {
        if ((millis() - antes))
        if (client.connect("carrinhoClient"))
        {
            client.subscribe("carrinho/controle/velocidade_max");
            client.subscribe("carrinho/controle/direcao_e_parada");
        }
    }
    else
    {
        client.loop();
    }
}

void setup()
{
    Serial.begin(9600);
    Motores mA(5, 23);
    Motores mB(12, 13);
    c.setMotorA(mA);
    c.setMotorB(mB);
    c.setupMotores();
}

void loop()
{
    c.frente();
    c.run();
}