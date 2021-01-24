#include "pilha.h"


//Pilha::Pilha (){
//    topo = NULL;
//}

//bool Pilha::pilhaVazia () const{
//    return (topo==NULL);
//}
////Contexto//pertence//nome do metodo
//Contato * Pilha::pop (){
//    if (pilhaVazia())
//    {
//        return NULL;
//    }
//    Contato * aux = topo;//Para não perder o endereço do que será retirado
//    topo = aux->getProximo();//Equivalente topo = topo -> getProximo();
//    aux->setProximo(NULL);
//    return aux;
//}

//void Pilha::push(Contato *novo)
//{
//    if (novo){
//        novo->setProximo(topo);
//        topo = novo;
//   }
//}

//Pilha::~Pilha()
//{
//    Contato * aux = NULL;
//    while (!pilhaVazia())
//    {
//        aux = pop();
//        delete aux;
//    }
//}
