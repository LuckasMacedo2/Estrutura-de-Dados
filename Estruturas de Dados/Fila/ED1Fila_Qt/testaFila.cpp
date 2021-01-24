
#include "testafila.h"

void TestaFila :: menu(){
    int tam, opc;
    Aluno *ptrAluno;
    bool enfilar;

    cout<<"\nInforme o tamanho da fila: ";
    cin>>tam;
    while (tam<0){
        cout<<"\nValor informado Inválido!\nInforme novamente: ";
        cin>>tam;
    }
    obj.setTam(tam);
    do
    {
        cout<<"\nInforme. \n(1)Para enfilheirar.  \n(2)Para desenfilheirar.  \n(3)Para sair. \nOpção: ";
        cin>>opc;
        while (opc<1||opc>3)
        {
            cout<<"\nInforme novamente! ";
            cout<<"\nInforme. \n(1)Para enfilheirar.  \n(2)Para desenfilheirar.  \n(3)Para sair. \nOpção: ";
            cin>>opc;
        }
        switch (opc)
        {
            case 1:
                ptrAluno = criaAluno ();
                enfilar = obj.enfilheirar(ptrAluno);
                if (enfilar)
                    cout<<"\nAluno adicionado na fila";
                else
                    cout<<"\nImpossivel adicionar o aluno na fila";
            break;

            case 2:
                ptrAluno = obj.desenfilheirar();
                if (ptrAluno)
                {
                    cout<<"\nAluno: ";
                    mostraAluno (ptrAluno);
                    cout<<"\n\nRemovido com sucesso!";
                }
                else
                {
                    cout<<"\nImpossivel remover o aluno da fila";
                }
            break;

            case 3:
                exit(1);
            break;
        }
    }while (opc!=3);
}

Aluno * TestaFila:: criaAluno (){
    Aluno * aux = new Aluno;
    string set;
    cout<<"\nInforme o nome do aluno: ";
    cin>>set;
    aux->setNome(set);
    cout<<"\nInforme o número de matricula do aluno: ";
    cin>>set;
    aux->setMat(set);
    cout<<"\nInforme o número de telefone do aluno: ";
    cin>>set;
    aux->setTel(set);
    return aux;
}

void TestaFila :: mostraAluno (Aluno * aux)
{
    Aluno * obj = new Aluno;
    obj = aux;
    cout<<"\n\n\n";
    cout<<"\nNome: "<<obj->getNome();
    cout<<"\nNúmero de Matricula: "<<obj->getMat();
    cout<<"\nNúmero de Telefone: "<<obj->getTel();
    cout<<"\n\n\n";
}



