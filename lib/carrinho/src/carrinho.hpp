#ifndef CARRINHO_H
#define CARRINHO_H
#include <motores.hpp>
//COMANDOS
#define FRENTE      'f'
#define RE          'r'
#define DIREITA     'd'
#define ESQUERDA    'e'
#define PARA        'p'

class Carrinho {
    public:
    Carrinho();

    Motores mA;//esquerdo
    Motores mB;//direto

    char cmd;

    const short pwmDeCurva = -100;
    const short pwmDeAcel = 30;

    void setMotorA(Motores m);
    void setMotorB(Motores m);
    void setComando(char c);
    void esquerda();
    void direita();
    void frente();
    void re();
    void para();
    void freia();
    void setVelocidadeMax(short v);
    void run();

};

#endif