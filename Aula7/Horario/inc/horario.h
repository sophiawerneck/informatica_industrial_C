#ifndef HORARIO_H
#define HORARIO_H

class Horario  //para armazenar horario do dia
{
private:  //cada um desses dados tem restriçoes, quero validar as informações que estão aqui, por isso cria o setHora
    int hora;  //possui 3 atributos privados, não da pra acessar diretamento da main, tem q fazer atraves das funções de acesso
    int minuto; //cada objeto vai ter hora, minuto e segundo
    int segundo;
public:
    Horario(int = 12, int = 0, int = 0);  

    // funções get
    int getHora() const;  //não recebe nada e retorna um inteiro
    int getMinuto() const;
    int getSegundo() const;

    // funções set
    void setHorario(int, int, int);  //recebe um valor e modifica o atributo
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);

    void imprimeHorario() const;
};

#endif