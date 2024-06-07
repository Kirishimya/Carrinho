#include <carrinho.hpp>//carrinho deve vir primeiro
#include <PubSubClient.h>
#include <WiFi.h>

Carrinho carrinho;
const char* ssid = "";
const char* senha = "";

const char* servidorMQTT = "";
int port = 1883;

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void callback(char *topic, byte *payload, unsigned int length);
void configurarServidorMQTT();
void reconnectMQTT();
void conectarWiFi();
void configurarCarrinho();

void setup() {
  Serial.begin(9600);
  delay(1000);
  conectarWiFi();
  configurarServidorMQTT();
  configurarCarrinho();
}

void loop() {
  reconnectMQTT();
  carrinho.run();
  delay(50);
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Payload recebido: ");
  Serial.println(*payload);
  if (strcmp(topic, "carrinho/controle/velocidade_max")) {
    short v = *payload;
    carrinho.setVelocidadeMax(v);
  }
  if (strcmp(topic, "carrinho/controle/direcao_e_parada")) {
    carrinho.setComando((char)*payload);
  }
}

void configurarServidorMQTT() {
  client.setServer(servidorMQTT, port);
  client.setCallback(callback);
}

void reconnectMQTT() {
  static unsigned long antes = millis();
  if (!client.connected()) {
    if ((millis() - antes) > 1000UL) {
      if (client.connect("carrinhoClient")) {
        client.subscribe("carrinho/controle/velocidade_max");
        client.subscribe("carrinho/controle/direcao_e_parada");
      }
    }
  } else {
    client.loop();
  }
}

void conectarWiFi() {
  WiFi.begin(ssid, senha);
  Serial.print("Conectando a rede WiFi ");
  Serial.println(ssid);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
  }
  Serial.println("Conectado!");
}

void configurarCarrinho() {
  Motores mA(5, 23);
  Motores mB(12, 13);
  carrinho.setMotorA(mA);
  carrinho.setMotorB(mB);
  carrinho.setupMotores();
}
