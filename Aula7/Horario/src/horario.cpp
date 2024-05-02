#include "horario.h"
#include "iostream"
#include <iomanip>

using namespace std;

Horario::Horario(int h , int m , int s)  //construtor da classe Horario
{
    //this->hora = (h>=0 && h<24) ? h : 0;  tá certo, mas vai modificar o atributo hora em 2 pontos
    //this->hora =h;  vai compilar mas conceitualmente n tá certo pq n faz nenhuma validaçao para inicializar a hora, se for -50000, vai inicializar -50000
    setHorario(h,m,s);//Define os horarios recebidos no construtor
}

void Horario::setHora(int h) //Define a hora se ela estiver dentro da condição h>=0 && h<24
{
    this->hora = (h>=0 && h<24) ? h : 0;//Essa linha diz basicamente, se h>=0 && h<24 faça this->hora = h, se não faça h=0 //this é um ponteiro para o objeto horario
    //é uma atribuição condicionada, faz uma atribuiçao de um valor para outro condicionado a uma expressao booleana
    //é igual a    if(h>=0 && h<24)
               //   this->hora = h;
               //  else 
               //   this->hora = 0; //atributo hora vais er igual a zero

}

void Horario::setMinuto(int m)//Define a hora se ela estiver dentro da condição m>=0 && m<60
{
    this->minuto = (m>=0 && m<60) ? m : 0;//Essa linha diz basicamente, se m>=0 && m<60 faça this->hora = m, se não faça m=0
}

void Horario::setSegundo(int s)//Define a hora se ela estiver dentro da condição s>=0 && s<60
{
    this->segundo = (s>=0 && s<60) ? s : 0;//Essa linha diz basicamente, se s>=0 && s<60 faça this->hora = s, se não faça s=0
}

void Horario::setHorario(int h, int m, int s)//Define os horarios recebidos no construtor
{
    setHora(h);  
    setMinuto(m);
    setSegundo(s);
}

int Horario::getHora() const //retorna a hora  //só le o valor do atributo hora, é um método para leitura de dados, ja bloqueia qualquer metodo de modificaçao
{
    return this->hora;
}

int Horario::getMinuto() const //retorna o minuto
{
    return this->minuto;
}

int Horario::getSegundo() const//retorna o segundo
{
    return this->segundo;
}

void Horario::imprimeHorario() const //retorna a hora no formato HH:MM:SS
{
    cout<<setfill('0')<<setw(2)<<this->getHora()<<":"<<setw(2)<<this->getMinuto()<<":"<<setw(2)<<this->getSegundo()<<endl;
}
// setfill preenche o número com 0 a esquerda, setw(2) para imprimir com 2 algarismos
