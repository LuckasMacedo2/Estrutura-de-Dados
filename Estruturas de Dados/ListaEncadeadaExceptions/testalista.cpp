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

void TestaLista::menuOrdenado(){
    int opc;
    Aluno * ptrAluno = new Aluno;
    ListaEncadeada obj;
    string buscar;

    do {
        cout<<"\nInforme\n[1]Para inserir o aluno ordenadamente \n[2]Para mostrar a lista ";
        cout<<"\n[3]Para buscar determinado aluno e retira-lo\n[4]Para sair \nOPÇÃO: ";
        cin>>opc;


        switch (opc){

            case 1:
                try {
                    ptrAluno = criaAluno();
                    if (ptrAluno){
                        obj.inserirOrdenado(ptrAluno);
                        cout<<"\nAluno adicionado com sucesso: ";
                        mostraAluno(ptrAluno);
                        cout<<"\n\n\n";
                    }
                    else
                    {
                        throw string ("\nErro, impossivel adicionar o aluno\n");
                    }
                } catch (string) {
                    cout<<"\nErro, impossivel inserir ordenadamente o aluno";
                }
            break;

            case 2:
                try {
                    string aux=obj.mostrar();
                    cout<<aux;
                } catch (string) {
                    cout<<"\nA lista encontra-se vazia. Impossivel mostra-la";
                }
            break;

            case 3:
            try {
                cout<<"\nInforme o nome do aluno: ";
                cin>>buscar;
                ptrAluno = obj.retirar(buscar);
                if (ptrAluno)
                {
                    cout<<"\n\n\nAluno removido com sucesso.";
                    mostraAluno(ptrAluno);
                    cout<<"\n\n\n";
                }
                else
                {
                    throw string ("erro");
                }
            } catch (string) {
                cout<<"\nERRo, impossivel remover aluno";
            }
            break;

        }
    }while (opc!=4);

}

void TestaLista::menu(){
    int opc;
    Aluno * ptrAluno = new Aluno;
    ListaEncadeada obj;

    do
    {
        opc = 0;
        while (opc<1 || opc>7){
            cout<<"\nInforme \n[1]Para Inserir aluno no final da lista \n[2]Para inserir aluno no inicio da fila ";
            cout<<" \n[3]Para retirar o aluno do inicio da lista";
            cout<<"\n[4]Para mostrar a lista. \n[5]Para sair \nOPÇÃo: ";
            cin>>opc;
        }
        switch (opc){
            case 1:
                try{
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
                        throw string ("\nNão é possivel adicionar o aluno informado");
                    }
                }catch (string)
                {
                    cout<<"\nErro, impossivel inserir aluno no final da lista\n";
                }

            break;
            case 2:
                try {
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
                        throw string ("\nErro, Aluno não adicionado");
                    }
                } catch (string ){
                    cout<<"\nErro, impossivel inserir aluno no inicio da lista";
                }
            break;
            case 3:
                try {
                    ptrAluno = obj.retirarInicio();
                    if (ptrAluno)
                    {
                        cout<<"\nAluno removido: ";
                        mostraAluno(ptrAluno);
                        cout<<"\n\n\n";
                    }
                    else
                    {
                        throw string ("\nErro, impossivel remover o aluno\n");
                    }
                } catch (string) {
                    cout<<"\nErro, impossivel retirar o aluno do inicio da lista";
                }
            break;
            case 4:
                try{
                    cout<<"\n"<<obj.mostrar();
                    cout<<"\n\n\n";
                }catch(string){
                    cout<<"\nA lista encontra-se vazia, impossivel exibi-la";
                }
            break;
        }
    }while (opc!=4);
}
