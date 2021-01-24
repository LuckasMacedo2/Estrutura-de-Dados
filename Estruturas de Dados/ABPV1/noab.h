#ifndef NOAB_H
#define NOAB_H
#include "item.h"

class NoAB
{
private:
    NoAB * pai, * esquerda, * direita;
    Item * dados;
public:
    NoAB();//O nó que trabalha na OAB
    void setPai (NoAB *);
    void setEsquerda (NoAB *);
    void setDireita (NoAB *);
    void setDados (Item *);
    NoAB * getPai () const;
    NoAB * getEsquerda () const;
    NoAB * getDireita () const;
    Item * getDados () const;

    static NoAB * montarNo (Item *);
    static Item * desmontarNo (NoAB *);
};

#endif // NOAB_H
