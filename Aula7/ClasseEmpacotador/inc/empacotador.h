#ifndef EMPACOTADOR_H
#define EMPACOTADOR_H

class Empacotador
{
private:
    int numEmpacotados;
    int id;
    static int totalEmpacotados; //quantidade de pacotes que o conjunto empacotou, dado compartilhado
public:
    Empacotador(int);//Construtor da classe Empacotador
    void empacotar(int);
    int getNumEmpacotados();
    static int getTotalEmpacotados();
    void imprimeNumEmpacotados();
    static void imprimeTotalEmpacotados(); //n está associado a nenhum objeto da classe empacotador pq é static, n tem acesso ao ponteiro this
};


#endif
