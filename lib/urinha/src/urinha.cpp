#include "motores.hpp"

Motores::Motores(short p1, short p2)
{
    this->p1 = p1;
    this->p2 = p2;
    pwm = 0;
    estado1 = 0;
    estado2 = 0;
}
Motores::Motores()
{
    pwm = 0;
    estado1 = 0;
    estado2 = 0;
}
void Motores::setP1(short p)
{
    p1 = p;
}
void Motores::setP2(short p)
{
    p2 = p;
}
void Motores::setSentido(short s)
{
    estado1 = (s == 1);
    estado2 = (s == 2);
}
void Motores::setPWM(short v)
{
    if (v > 255)    pwm = 255;
    else if (v < 0) pwm = 0;
    else            pwm = v;
}
void Motores::desliga()
{
    pwm = 0;
    estado1 = 0;
    estado2 = 0;
}
void Motores::run()
{
    analogWrite(p1, estado1*pwm);
    analogWrite(p2, estado2*pwm);
}