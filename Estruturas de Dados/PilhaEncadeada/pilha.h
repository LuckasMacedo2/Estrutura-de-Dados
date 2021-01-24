#ifndef PILHA_H
#define PILHA_H
#include"contato.h"
class Pilha{
private:
    Contato * topo;
public:
    void push (Contato *);
    Contato * pop ();
    bool pilhaVazia () const;
    Pilha();
    ~Pilha();

};

#endif // PILHA_H
