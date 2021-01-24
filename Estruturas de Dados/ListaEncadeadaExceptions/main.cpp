#include <iostream>
#include "testalista.h"
using namespace std;

int main()
{
    int opc;
    TestaLista obj;
    do{
        do{
            cout<<"\nInforme \n[1]Para operações com lista ordenada \n[2]Para operações com lista desordenada";
            cout<<"\nOPÇÃO ";
            cin>>opc;
        if (opc==1)
            obj.menuOrdenado();
        else
            if (opc==2)
                obj.menu();
        }while (opc<1 || opc>3);
    }while (opc!=3);
    return 0;

}
