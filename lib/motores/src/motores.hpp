#ifndef MOTORES_H
#define MOTORES_H
#include <Arduino.h>

class Motores {
    public:
    Motores(short p1, short p2);
    Motores();

    short p1, p2;
    short pwm, maxPwm;
    short estado1, estado2;
    uint8_t sentido;
    void setP1(short p);
    void setP2(short p);
    void setSentido(short s);
    void setPWM(short v);
    //controle de velocidade maxima
    void setMaxPWM(short v);
    short getMaxPWM();
    void addPWM(short v);
    void desliga();
    void run();
};

#endif