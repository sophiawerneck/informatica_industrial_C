#include <iostream>
#include <string>
#include <vector>
#include "formas.h"

using namespace std;

void foo(vector<FormaBiDimensional*> formas)   //programada para a classe base 
{
    for(int i=0;i<formas.size();++i)
    {                                       //vetor de ponteiros -> //vetor de objeto usa ponto
        cout <<"Area objeto " << i<<" : " << formas[i]->calculaArea()<<endl;//Cada objeto vai realizar seu proprio metodo de calcular a Area
    }  //calculaArea() vai assumir mutiplas formas de acordo com o objeto q estou manipulando, é onde tem o polimorfismo
}

int main()
{

    Circulo c(3);//Circulo de Raio 3
    Quadrado q(4);//Quadrado de Lado 4
    FormaBiDimensional* vet[2];
    vector<FormaBiDimensional*> formas;
    formas.push_back(&c);
    formas.push_back(&q);
    int a = 10;

    vet[0] = &c;
    vet[1] = &q;
    foo(formas);

    system("pause");

    return 0;
}
