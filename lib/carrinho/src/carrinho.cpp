#include "carrinho.hpp"

void Carrinho::setMotorA(Motores m)
{
    mA = m;
}
void Carrinho::setMotorB(Motores m)
{
    mB = m;
}
void Carrinho::setComando(char c)
{
    cmd = c;
}
void Carrinho::esquerda()
{
    mB.setPWM(mB.getMaxPWM());
    mB.addPWM(pwmDeCurva);
}
void Carrinho::direita()
{
    mA.setPWM(mA.getMaxPWM());
    mA.addPWM(pwmDeCurva);
}
void Carrinho::frente()
{
    static unsigned long antes = millis();
    mA.setSentido(1);
    mB.setSentido(1);
    if((millis() - antes) > 1000) {
        antes = millis();
        mA.addPWM(pwmDeAcel);
        mB.addPWM(pwmDeAcel);
    }
}
void Carrinho::re()
{
    static unsigned long antes = millis();
    mA.setSentido(2);
    mB.setSentido(2);
    if((millis() - antes) > 1000) {
        antes = millis();
        mA.addPWM(pwmDeAcel);
        mB.addPWM(pwmDeAcel);
    }
}
void Carrinho::para()
{
   mA.desliga();
   mB.desliga();
}
void Carrinho::freia()
{
    static unsigned long antes = millis();
    if((millis() - antes) > 1000) {
        antes = millis();
        mA.addPWM(-pwmDeAcel);
        mB.addPWM(-pwmDeAcel);
    }
}
void Carrinho::setVelocidadeMax(short v)
{
    mA.setMaxPWM(v);
    mB.setMaxPWM(v);
}
void Carrinho::run() 
{
    switch(cmd) {
        case FRENTE: frente();
        break;
        case RE: re();
        break;
        case DIREITA: direita();
        break;
        case ESQUERDA: esquerda();
        break;
        case PARA: para();
        break;
        default: //freia();
        break;
    }
    mA.run();
    mB.run();
}
void Carrinho::setupMotores()
{
    mB.setup();
    mA.setup();
}