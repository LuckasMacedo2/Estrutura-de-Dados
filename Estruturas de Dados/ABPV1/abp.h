#ifndef ABP_H
#define ABP_H
#include "noab.h"

class ABP
{
private:
    NoAB * raiz;
    NoAB * nulo = new NoAB;
    NoAB * busca (Item *) const;
    void imprimirPreOrdem (NoAB * aux, string &ret) const; //TestaArvore
    void imiprimirEmOrdem (NoAB *, string &) const;
    void imprimirPosOrdem (NoAB *, string &)const;
    void testaIntegridadeABP(NoAB *, string&);
public:
    ABP();
    bool arvoreVazia () const;
    bool inserir (Item *);
    Item * retirar (Item *);
    Item * pesquisar (Item *) const;
    NoAB * minimo (NoAB *);
    NoAB * maximo (NoAB *);
    NoAB * sucessor (NoAB *);
    NoAB * antecessor (NoAB *);

    void imprimirPreOrdem(string & aux) const{
        imprimirPreOrdem(raiz, aux);
    }

    void imprimirEmOrdem (string & aux) const{
        imiprimirEmOrdem (raiz, aux);
    }

    void imprimirPosOrdem (string & aux)const{
        imprimirPosOrdem (raiz, aux);
    }

    void testaIntegridadeABP(string & aux){
        testaIntegridadeABP(raiz, aux);
    }
};

#endif // ABP_H
