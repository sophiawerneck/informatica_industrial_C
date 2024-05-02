#include <iostream>
#include "horario.h"

using namespace std;

int main()
{
    //Horario h1;
    //Horario h3(15,16);  pode ser utilizado
    //Horario h4(16,17,30); //pode ser utilizado
    Horario h1(15);
    //const Horario h1(15); vai ser construido e após a construção n poderá ser alterado mais, tem que definir as funções get e imprimeHorario como const também
    h1.imprimeHorario();
    //h4.imprimeHorario();
    system("pause");

    return 0;
}
