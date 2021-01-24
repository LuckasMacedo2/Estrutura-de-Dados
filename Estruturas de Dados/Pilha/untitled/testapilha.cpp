#include "testapilha.h"
#include <iostream>
using std :: cout;
using std :: cin;
        livro * TestaPilha :: criaLivro()
        {
            livro * obj = new livro;
            string aux;
            short int valor;
            cin.ignore();
            cout<<"\nDigite o nome do livro: ";
            getline(cin, aux);
            obj->setTitulo(aux);
            cout<<"\nDigite o nome do autor: ";
            getline(cin, aux);
            obj->setAutor(aux);
            cout<<"\nDigite o nome da Editora: ";
            getline(cin, aux);
            obj->setEditora(aux);
            cout<<"\nInforme o Ano: ";
            cin>>valor;
            while (valor<0)
            {
                cout<<"\nAno Informado invalido, informe novamente: ";
                cin>>valor;
            }
            obj->setAno(valor);
            cout<<"\nInforme a edição: ";
            cin>>valor;
            while (valor<0)
            {
                cout<<"\nEdição Informada invalida, informe novamente: ";
                cin>>valor;
            }
            obj->setEd(valor);
            cout<<"\nInforme a quantidade de paginas do livro: ";
            cin>>valor;
            while (valor<0)
            {
                cout<<"\nQuantidade de paginas Informadas invalidas, informe novamente: ";
                cin>>valor;
            }
            obj->setNumPags(valor);
            cout<<"\nInforme o volume: ";
            cin>>valor;
            while (valor<0)
            {
                cout<<"\nAno Informado invalido, informe noamente: ";
                cin>>valor;
            }
            obj->setVol(valor);
            return obj;


        }
        void TestaPilha ::mostraLivro (livro * aux)
        {
            cout<<"\n\n\n";
            livro * obj = new livro;
            obj = aux;
            cout<<"\nTitulo: "<<obj->getTitulo();
            cout<<"\nAutor: "<<obj->getAutor();
            cout<<"\nEditora: "<<obj->getEditora();
            cout<<"\nAno: "<<obj->getAno();
            cout<<"\nEdição: "<<obj->getEd();
            cout<<"\nNúmero de Paginas: "<<obj->getNumPags();
            cout<<"\nValor: "<<obj->getVol();
            cout<<"\n\n\n";
        }

        void TestaPilha ::menu ()
        {
            Pilha obj;
            livro * aux = 0;
            bool ok;
            int opc, tam;
            cout<<"\nInforme o tamanho do vetor: ";
            cin>>tam;
            obj.setTamanho(tam);
            do
            {
                cout<<"\nInforme \n(1)Para empilhar \n(2)Para desempilhar \n(3)Para sair \nOpção: ";
                cin>>opc;
                while (opc<1 || opc>3)
                {
                    cout<<"\nInforme novamente: ";
                    cin>>opc;
                };
                switch (opc)
                {
                    case 1:
                        aux = criaLivro ();
                        ok = obj.push(aux);
                        if (ok)
                            cout<<"\nSucesso\n\n";
                        else
                            cout<<"\nErro\n\n";
                    break;
                    case 2:
                        mostraLivro(aux);
                        aux = obj.pop();
                        if (aux)
                        {
                            cout<<"\nRemovido";
                        }
                        else
                        {
                             cout<<"\nErro";
                        }
                    break;
                    case 3:
                        exit (1);
                    break;
                }
            }while(opc!=3);
        }
