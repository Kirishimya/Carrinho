#include <carrinho.hpp>
Carrinho c;
void setup() {
    Serial.begin(9600);
    Motores mA(5, 23);
    Motores mB(12, 13);
    c.setMotorA(mA);
    c.setMotorB(mB);
    c.setupMotores();
    
}

void loop() {
    c.frente();
    c.run();
}