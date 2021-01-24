#include "testaarvore.h"

TestaArvore::TestaArvore()
{
}

void TestaArvore::menu()
{
    try {
        int opc;
        Item * ptrItem = new Item;
        ABP * ptrABP = new ABP;
        do {
            cout<<"\nInforme \n[1]Para inserir \n[2]Para retirar \n[3]Para imprimir em Ordem \n[4]Para imprimir em Pós Ordem";
            cout<<"\n[5]Para imprimir em Pré ordem \n[6]Para testar a integridade da arvore \n[7]Para Pesquisar \n[8]Para sair \nOpção: ";
            cin>>opc;
            //system("clear");
            //system("cls");
            switch (opc) {
                case 1:
                    try {
                        ptrItem = TestaArvore::criarItem();
                        if(!ptrItem){
                            throw string ("\nErro ao inicializar o objeto!");
                        }
                        if(ptrABP->inserir(ptrItem))
                            cout<<"\nObjeto inserido com sucesso";
                        else
                            cout<<"\nErro";
                    } catch (string &erro) {
                        cout<<erro;
                    }

                break;
                case 2:
                    try {
                        Item * busca = new Item;
                        busca = criarItem();
                        if (!ptrItem){
                            throw string ("\nErro, impossivel remover o objeto");
                        }
                        ptrItem = ptrABP->retirar(busca);
                        cout<<"\n\nObjeto removido com sucesso!\n\n";
                        imprimirItem(ptrItem);
                        delete ptrItem;
                    } catch (string &erro) {
                        cout<<erro;
                    }
                    catch (std::bad_alloc &){
                        cout<<"\nErro, falta de memoria";
                    }

                break;
                case 3:
                  try {
                       string imprimir = "\nA arvore impressa é: \n";
                       ptrABP->imprimirEmOrdem(imprimir);
                       cout<<"\n"<<imprimir;
                   } catch (string &erro) {
                        cout<<erro;
                   }
                break;
                case 4:
                    try {
                         string imprimir = "\nA arvore impressa é: \n";
                         ptrABP->imprimirPreOrdem(imprimir);
                         cout<<"\n"<<imprimir;
                     } catch (string &erro) {
                          cout<<erro;
                     }
                break;
                case 5:
                    try {
                         string imprimir = "\nA arvore impressa é: \n";
                         ptrABP->imprimirPosOrdem(imprimir);
                         cout<<"\n"<<imprimir;
                     } catch (string &erro) {
                          cout<<erro;
                     }
                break;
                case 6:
                    try {
                        string imprimir = "\nVerificando a integridade da arvroe \n";
                        ptrABP->testaIntegridadeABP(imprimir);
                        cout<<"\n"<<imprimir;
                    } catch (...) {
                        cout<<"\nERRO";
                    }
                break;
                case 7:
                    try {
                        cout<<"\nInforme: ";
                        Item * pesq = new Item;
                        pesq = criarItem();
                        ptrItem = ptrABP->pesquisar(pesq);
                        if (ptrItem)
                            imprimirItem(ptrItem);
                        else
                            cout<<"\nObjeto informado inválido";
                    } catch (string &erro) {
                        cout<<erro;
                    }
                    catch (std::bad_alloc &){
                        cout<<"\nErro, falta de memoria";
                    }
                break;
                case 8:
                    exit(1);
                break;
                default:
                    cout<<"\nErro! Opção inválida";
                break;
            }
        } while (opc!=8);
    } catch (std::bad_alloc &) {
        cout<<"\nErro, memoria para armzenamento insuficiente";
    }
}

Item * TestaArvore::criarItem()
{
    try {
        Item * aux = new Item;
        int key;
        string nome;
        cout<<"\nInforme o nome: ";
        cin>>nome;
        cout<<"\nInforme a chave: ";
        cin>>key;
        aux->setNome(nome);
        aux->setKey(key);
        return aux;
    } catch (std::bad_alloc &) {
        throw string ("\nErro, memoria para armzenamento insuficiente");
    }

}

void TestaArvore::imprimirItem(Item * obj)
{
    cout<<"\nNome: "<<obj->getNome();
    cout<<"\nKey: "<<obj->getKey();
    cout<<"\n\n";
}
