#ifndef PILHA_H
#define PILHA_H
#include"contato.h"

template <class tipo>
class Pilha{
private:
    tipo * topo;
public:
    void push (tipo *);
    tipo * pop ();
    bool pilhaVazia () const;
    Pilha<tipo>();
    ~Pilha<tipo>();

};

template <class tipo>
Pilha<tipo>::Pilha (){
    topo = NULL;
}

template <class tipo>
bool Pilha<tipo>::pilhaVazia () const{
    return (topo==NULL);
}

template <class tipo>
//Contexto//pertence//nome do metodo
tipo *Pilha<tipo>::pop(){
    if (pilhaVazia())
    {
        return NULL;
    }
    tipo * aux = topo;//Para não perder o endereço do que será retirado
    topo = aux->getProximo();//Equivalente topo = topo -> getProximo();
    aux->setProximo(NULL);
    return aux;
}

template <class tipo>
void Pilha<tipo>::push(tipo *novo)
{
    if (novo){
        novo->setProximo(topo);
        topo = novo;
   }
}

template <class tipo>
Pilha<tipo>::~Pilha()
{
    Contato * aux = NULL;
    while (!pilhaVazia())
    {
        aux = pop();
        delete aux;
    }
}

#endif // PILHA_H
