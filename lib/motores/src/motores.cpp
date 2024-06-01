#include "motores.hpp"

Motores::Motores(short p1, short p2)
{
    this->p1 = p1;
    this->p2 = p2;
    sentido = 1;
    pwm = 0;
    estado1 = 0;
    estado2 = 0;
}
Motores::Motores()
{
    sentido = 1;
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
    if (sentido != s)
    {
        sentido = s;
        estado1 = (s == 1);
        estado2 = (s == 2);
        pwm = 0;
    }
}
void Motores::setPWM(short v)
{
    if (v > maxPwm)
        pwm = maxPwm;
    else if (v < 0)
        pwm = 0;
    else
        pwm = v;
}
void Motores::setMaxPWM(short v)
{
    if (v > 255)
        maxPwm = 255;
    else if (v < 0)
        maxPwm = 0;
    else
        maxPwm = v;
}
void Motores::addPWM(short v)
{
    setPWM(pwm + v);
}
short Motores::getMaxPWM()
{
    return maxPwm;
}
void Motores::desliga()
{
    pwm = 0;
    estado1 = 0;
    estado2 = 0;
}
void Motores::run()
{
    analogWrite(p1, estado1 * pwm);
    analogWrite(p2, estado2 * pwm);
}