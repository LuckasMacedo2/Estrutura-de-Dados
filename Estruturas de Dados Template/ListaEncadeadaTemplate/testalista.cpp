#include "testalista.h"
#include <iostream>
using std::cout;
using std::cin;

Aluno * TestaLista::criaAluno(){
    string nome, mat;
    Aluno *obj = new Aluno;
    No *no = new No;

    cout<<"\nInforme o nome do aluno: ";
    cin>>nome;
    obj->setNome(nome);
    cout<<"\nInforme o número de matricula do Aluno: ";
    cin>>mat;
    obj->setMat(mat);
    cout<<"\n\n\n";

    no->setDados(obj);
    no->montarNo(obj);
    return obj;
}

void TestaLista::mostraAluno (Aluno * aux)
{
    No * no = new No;
    no->setDados(aux);
    cout<<"\nNome: "<<no->getDados()->getNome();
    cout<<"\nNúmero de Matricula: "<<no->getDados()->getMatricula();
}

void TestaLista::menu(){
    int opc;
    Aluno * ptrAluno = new Aluno;
    ListaEncadeada<Aluno> obj;
    string buscar;

    do
    {
        opc = 0;
        while (opc<1 || opc>7){
            cout<<"\nInforme \n[1]Para Inserir aluno no final da lista \n[2]Para inserir aluno no inicio da fila ";
            cout<<"\n[3]Para inserir ordenadamente o aluno \n[4]Para retirar o aluno do inicio da lista \n[5]Para buscar determinado aluno na lista e remove-lo";
            cout<<"\n[6]Para mostrar a lista. \n[7]Para sair \nOPÇÃo: ";
            cin>>opc;
        }
        switch (opc){
            case 1:
                ptrAluno = criaAluno();
                if (ptrAluno)
                {
                    obj.inserirFinal(ptrAluno);
                    cout<<"\nAluno adicionado com sucesso: ";
                    mostraAluno(ptrAluno);
                    cout<<"\n\n\n";
                }
                else
                {
                    cout<<"\nERRO, Impossivel adicionar o aluno na Lista\n\n\n";
                }
            break;
            case 2:
                ptrAluno = criaAluno();
                if (ptrAluno)
                {
                    obj.inserirInicio(ptrAluno);
                    cout<<"\nAluno adicionado com sucesso: ";
                    mostraAluno(ptrAluno);
                    cout<<"\n\n\n";
                }
                else
                {
                    cout<<"\nERRO, Impossivel adiocionar o aluno na lista\n\n\n";
                }
            break;
            case 3:
                ptrAluno = criaAluno();
                if (ptrAluno){
                    obj.inserirOrdenado(ptrAluno);
                    cout<<"\nAluno adicionado com sucesso: ";
                    mostraAluno(ptrAluno);
                    cout<<"\n\n\n";
                }
                else
                {
                    cout<<"\nERRO, Impossivel adicionar o aluno na lista\n\n\n";
                }
            break;
            case 4:
                ptrAluno = obj.retirarInicio();
                if (ptrAluno)
                {
                    cout<<"\nAluno removido: ";
                    mostraAluno(ptrAluno);
                    cout<<"\n\n\n";
                }
                else
                {
                    cout<<"\nERRO, impossivel remover o aluno do inicio da fila";
                    cout<<"\n\n\n";
                }
            break;
            case 5:
                cout<<"\n\n\n";
                cout<<obj.mostrar()<<"\n";
                if (obj.listaVazia())
                {
                    cout<<"\nImpossivel realizar a operação com  a lista vazia\n\n\n";
                }
                else{
                    cout<<"\nInforme o nome do aluno: ";
                    cin>>buscar;
                    ptrAluno = obj.retirar(buscar);
                    if (ptrAluno)
                    {
                        cout<<"\nAluno removido com sucesso!";
                        cout<<"\n";
                        mostraAluno(ptrAluno);
                        cout<<"\n\n\n";
                    }
                    else
                    {
                        cout<<"\nERRO, aluno não econtrado.";
                        cout<<"\n\n\n";
                    }
                }
            break;
            case 6:
                cout<<"\n"<<obj.mostrar();
                cout<<"\n\n\n";
            break;
        }
    }while (opc!=7);
}
