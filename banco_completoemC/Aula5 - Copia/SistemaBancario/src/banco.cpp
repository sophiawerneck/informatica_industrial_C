 #include "banco.h"
#include <iostream>

using namespace std;

Banco::Banco() //O construtor criara 4 contas
{
    this->senhaGerente = 1357;
    
    this-> numeroAtualdeContas = 4;
    this-> pContas = new Conta[this -> numeroAtualdeContas];
    
    this-> pContas[0] = {1234, 1, "Joao", "Corrente", 300};
    this-> pContas[1] = {4567, 2, "Jose", "Poupanca", 800};
    this-> pContas[2] = {7890, 3, "Maria", "Corrente", 1000};
    this-> pContas[3] = {8956, 4, "Madalena", "Poupanca", 2000};
}

Banco::~Banco()
{
    delete[] pContas;
}

Conta *Banco::buscaConta(int numero)//Retorna o endereço da conta que possuir o mesmo numero informado
{
    for (int i = 0; i < numeroAtualdeContas; i++)
    {
        if (numero == this->pContas[i].numero)
        {
            return &this->pContas[i];
        }
    }

    return nullptr;
}


void Banco::atendimento()
{   
    int escolha; //variável para identificar se é gerente ou cliente
    bool status_atendimento = true; //ussa essa e a de baixo como false para quando a pessoa selecionar "sair"
    bool atendimento_geral = true; //usa essa variavel como condicao para iniciar o sistema de atendimento
    while(atendimento_geral){
        cout<<"Bem vindo ao sistema de atendimento do banco "<<endl;
        cout<<"O que você deseja: 1- Atendimento ao Cliente, 2- Atendimento ao Gerente, 3 - Sair"<<endl;
        cin>>escolha;
    
        switch(escolha){ //execulta uma acao de acordo com a escolha
            while(status_atendimento){
                case 1:
                this -> atendimentoCliente(); //objeto aponta pra atendimento ao cliente
                break;
            case 2:
                this -> atendimentoGerente();
                break;
            case 3:
                status_atendimento = false;
                atendimento_geral = false;
                break;
            }
        }
    }
}


bool Banco::atendimentoCliente() //Realiza o atendimento ao cliente(Função chamada na main)
{
    Conta *contaCliente;
    int numC = 0;
    int senhain;
    bool atendimento = true;

    cout << "Bem vindo ao sistema de atendimento ao Cliente" << endl;
    
    cout << "Digite o numero da sua conta: ";
    cin >> numC;
    
    contaCliente = this->buscaConta(numC);

    if (contaCliente == nullptr)//Se não achar nenhuma conta que corresponda entra nesse if
    {
        cout << "Conta invalida" << endl;
    }
    else
    {
        cout << "Digite a sua senha: ";
        cin >> senhain;

        if (contaCliente->validaSenha(senhain))
        {
            cout << "Ola " << contaCliente->titular << endl;
            while (atendimento) //Realiza o atendimento
            {
                int op;
                double valor;
                cout << "Qual operacao deseja fazer? (1 - Saque, 2 - Deposito, 3 - Ver Saldo, 4 - Sair, 5 - Transferência): ";
                cin >> op;
                switch (op)
                {
                case 1:
                    cout << "Digite o valor: ";
                    cin>>valor;
                    contaCliente->saque(senhain,valor);
                    break;
                case 2:
                    cout << "Digite o valor: ";
                    cin>>valor;
                    contaCliente->deposito(valor);
                    break;
                case 3:
                    cout << "Saldo: R$ "<<contaCliente->getSaldo(senhain)<<endl;
                    break;
                case 4:
                    atendimento = false;
                    break;
                case 5:
                    cout << "Para qual conta deseja fazer a transferência: ";
                    cin >> numC;
                    cout << "Digite o valor que deseja transferir: ";
                    cin >> valor;
                    Conta* contaDest;
                    contaDest = buscaConta(numC);
                    contaCliente->transferencia(valor,contaDest);
                    break;
                }
            }
        }
            else
            {
                cout << "Senha invalida" << endl;
            }
    }
    return atendimento;
}
    
    
bool Banco::atendimentoGerente()
{
    int senhain;
    bool atendimento = true;
    
    cout<<"Bem vindo Gerente!"<<endl;
    cout << "Digite a sua senha: ";
    cin >> senhain;
    
    if(this->senhaGerente == senhain)
    {
        cout << "Ola "<<endl;
        
        while(atendimento)
        {
            int op;
            cout << "Qual operacao deseja fazer? (1 - Criar nova Conta, 2 - Sair): ";
            cin >> op;
            switch (op)
            {
            case 1:
                this ->criaConta(senhain);
                break;
            case 2:
                atendimento = false;
                break;
            }
        }
        
    }
    else
    {
        cout << "Senha invalida" << endl;
    }
    return atendimento;
}


int Banco::getNumeroAtualContas(int senha)
{
    if (this->senhaGerente==senha)
    {
        return this->numeroAtualdeContas;
    }
    else
    {
        cout<<"Senha inválida";
        return -10000;
    }
}


void Banco::criaConta(int senha)
{
    //verificar se os valores e nomes já foram utilizados para criar novas contas
    int senhaConta, numeroContas; //numeroContas é o numero de contas existentes
    string titularConta, tipoConta;
    double saldoConta;
    
    numeroContas = getNumeroAtualContas(senha);
    pAux = new Conta[numeroContas+1];
    
    for(int i = 0; i<numeroContas ; i++) //esta compiando o que tinha no vetor pContas para o vetor pAux
    { 
        pAux[i] = pContas[i];
    }
    
    delete[] this->pContas; //deletando o que estava armazenado no vetor pContas
   
    cout<<"Entre com os dados da nova conta: "<<endl;
    cout << "Digite o nome do titular: ";
    cin >> titularConta;
    pAux[numeroContas].titular = titularConta; //vai ser entre colchetes "numeroContas" pois o indice do vetor começa em 0,
    //logo a posição numeroContas é a ultima do vetor pAux (que tem tamanho numeroContas+1)
    
    cout << "Digite o tipo de conta: ";
    cin >> tipoConta;
    pAux[numeroContas].tipo = tipoConta;

    cout << "Digite o saldo: ";
    cin >> saldoConta;
    pAux[numeroContas].setSaldo(saldoConta);

    cout << "Digite a senha: ";
    cin >> senhaConta;
    pAux[numeroContas].setSenha(senhaConta);
    
    pAux[numeroContas].numero = (numeroContas + 1);
    
    cout<<"Conta criada com sucesso "<<endl;


    pContas = new Conta[(numeroContas) + 1];
    
    for(int i = 0; i<(numeroContas + 1) ; i++){
        pContas[i] = pAux[i];
    }
    
    delete[] this->pAux;
    
    this->numeroAtualdeContas++;
    cout<<"Número atual de contas: "<<this->numeroAtualdeContas<<endl;
}