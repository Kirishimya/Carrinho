#ifndef MOTORES_H
#define MOTORES_H
#include <Arduino.h>

class Motores {
    public:
    Motores(short p1, short p2);
    Motores();

    short p1, p2;
    short pwm;
    short estado1, estado2;

    void setP1(short p);
    void setP2(short p);
    void setSentido(short s);
    void setPWM(short v);
    void desliga();
    void run();
};

#endif