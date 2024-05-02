#ifndef BANCO_H
#define BANCO_H

#include "conta.h"

#define NUMCONTAS 100 //Define que a palavar NUMCONTAS passa a valer como escrever 100

class Banco
{
private:
    //Conta contas[NUMCONTAS]; Cria um vetor de objetos do tipo Conta que pode armazenar até 100 contas
    //nao quero mais que seja um vetor estático
    int senhaGerente;
    int numeroAtualdeContas;
    
    Conta* pContas; //vetor de Contas
    Conta* pAux;
public:
    Banco();
    ~Banco();
    Conta* buscaConta(int numero); //Metodo que retorna o endereço do objeto conta que possui o mesmo numero informado
    void atendimento();
    bool atendimentoCliente();
    bool atendimentoGerente();
    int getNumeroAtualContas(int senha);
    void criaConta(int senha);
};


#endif