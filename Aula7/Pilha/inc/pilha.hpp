//Esse arquivo recebe a extensão hpp por possuir um template
#ifndef PILHA_H
#define PILHA_H

template<typename T>//T fica definido como uma "variavel" para os tipos dos atributos e metodos, como por exemplo: int,float,bool...
class Pilha //primeiro número armazenado é o último a ser retirado
{
private:
    int tam;
    int top;
    T *pPtr;//pPtr apontara para o tipo de variavel definido no main no momento de sua declaração //ponteiro para um tipo genérico
public:
    Pilha(int = 10);
    ~Pilha();
    bool insere(const T&);
    bool remove(T&);
    bool estaVazia() const;
    bool estaCheia() const;
};


template<typename T>
Pilha<T>::Pilha(int t)//Cria uma vetor de tamanho variavel do tipo T
{
    this->tam = t > 0 ? t:10;//Essa linha diz: Se t>0, this->tam = t, senão: this->tam=10
    this->top = -1;  //posiçao do último dado inserido
    this->pPtr = new T[this->tam];
}

template<typename T>
Pilha<T>::~Pilha()//Deleta o vetor criado no construtor
{
    delete[] this->pPtr;
}

template<typename T>
bool Pilha<T>::insere(const T& valor)//Insere um valor no topo da pilha//é passagem por referência(gasta menos e é mais rápido)/bool insere(T valor) é por valor, então é pior
{ //const pra aqui dentro n modificar o valor original 
    if(!estaCheia()) //se n estiver cheia vai inseririr o dado
    {
        pPtr[++top] = valor; //pré incremento, vale -1 e com o ++top vai ser =0, insere na posição 0
        return true;
    }
    else
    {
       return false;  
    }    
}

template<typename T>
bool Pilha<T>::remove(T& var)//Remove o ultimo elemento inserido na pilha e atribui a var o valor do dado removido(passagem por referencia)
{
    if(!estaVazia())  //verifica se o top = -1, se n for =-1:
    {
        var = pPtr[top--]; //se o top vale 2, o top cai 1 valor pra baixo
        return true;
    }
    else
    {
        return false;
    }
    
}

template<typename T>
bool Pilha<T>::estaVazia() const//Verifica se a pilha esta vazia
{
    return top == -1;
}

template<typename T>
bool Pilha<T>::estaCheia() const//Verifica se a pilha esta cheia  //verifica se o top chegou no final
{
    return top == tam - 1;
}


#endif
