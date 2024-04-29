#ifndef CONTA_H
#define CONTA_H
#include <string>


class Conta
{
private:
    double saldo; //atributo
    int senha;    //atributo
public:
    Conta();//Construtor  //tem 2 construtores: sobrecarga  //função dos construtores: inicializar atributos
    Conta(int senha, int numero, std::string titular, std::string tipo, double saldo);//Construtor que recebe parametros
    ~Conta();//Destrutor //é automaticamente invocado quando o objeto sai do escopo //destroi os objetos
    int numero; //atributo
    std::string titular; //atributo
    std::string tipo; //atributo
    void exibeDados(); //método
    double getSaldo(int senha); //método para retornar o saldo, é preciso do atributo senha para obter o saldo
    void setSaldo(double valor); //método para configurar o saldo
    void setSenha(int novaSenha); //método para configurar a senha
    void deposito(double valor); //método para depositar um valor
    void saque(int senha, double valor); //método para sacar um valor

};


#endif
