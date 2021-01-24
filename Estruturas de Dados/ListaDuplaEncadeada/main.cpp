#include "testaordenado.h"


int main ()
{
    setlocale(LC_ALL,"");
    TestaOrdenado obj;
    for(int i=0;i!=3;){
        system("cls");
        //system("clear");
        cout<<"<1>lista ordenada\n<2>lista desordenada\n<3>sair\nOpção ";
        cin>>i;
        switch (i) {
        case 1:
            obj.menu();
            break;
        case 2:
            obj.menu2();
            break;
        case 3:
            cout<<"FIM!\n";
            exit(1);
            break;
        default:
            cout<<"esta opção não esta no menu\n";
            break;
        }


    }

}
