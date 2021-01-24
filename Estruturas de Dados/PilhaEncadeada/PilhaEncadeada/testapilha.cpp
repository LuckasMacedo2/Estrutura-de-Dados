#include "testapilha.h"
#include <iostream>
using std :: cin;
using std :: cout;

Contato *TestaPilha::criarContato(){

    Contato * aux = new Contato;
    string nome, num;
    cout<<"\nInforme o nome: ";
    cin>>nome;
    aux->setNome(nome);
    cout<<"\nInforme o número de telefone: ";
    cin>>num;
    aux->setTel(num);

    return aux;

}

void TestaPilha::mostrarContato(Contato * aux)
{
    cout<<"\nNome: "<<aux->getNome();
    cout<<"\nNúmero de telefone: "<<aux->getTel();
}

void TestaPilha ::menu()
{
    int opc;
    Contato * aux = new Contato;
    do{
        cout<<"\nInforme \n(1)Para adicionar um novo contato. \n(2)Para retirar o último contato adicionado. \n(3)Para sair. \nOPÇÃO: ";
        cin>>opc;
        while (opc<1 || opc>3)
        {
            cout<<"\nInválido, informe novamente!";
            cout<<"\nInforme \n(1)Para adicionar um novo contato. \n(2)Para retirar o último contato adicionado. \n(3)Para sair. \nOPÇÃo";
            cin>>opc;
        }
        switch (opc)
        {
            case 1:
                aux = criarContato();
                if (aux){
                    obj.push(aux);
                    cout<<"\nContato Inserido com sucesso.\n\n";
                }
                else
                {
                    cout<<"\nErro ao inserir o Contato\n\n";
                }
            break;

            case 2:
                aux = obj.pop();
                if (aux)
                {
                    mostrarContato(aux);
                    cout<<"\n\nContato Removido com sucesso.\n\n";
                }
                else
                {
                    cout<<"\n\nImpossivel remover contato.";
                }
            break;

            case 3:
                exit(1);
            break;

        }
    }while (opc!=3);
}
