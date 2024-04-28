#include <iostream>
#include "horario.h"

using namespace std;

int main()
{
    //Horario h1;
    //Horario h3(15,16);  pode ser utilizado
    //Horario h4(16,17,30); //pode ser utilizado
    Horario h1(15);

    h1.imprimeHorario();
    //h4.imprimeHorario();
    system("pause");

    return 0;
}
