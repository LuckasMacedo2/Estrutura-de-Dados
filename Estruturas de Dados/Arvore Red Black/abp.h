#ifndef ABP_H
#define ABP_H
#include "noab.h"

class ABP
{
private:
    NoAB * nulo;
    NoAB * raiz;
    NoAB * busca (Item *) const;
    void imprimirPreOrdem (NoAB * aux, string &ret) const; //TestaArvore
    void imiprimirEmOrdem (NoAB *, string &) const;
    void imprimirPosOrdem (NoAB *, string &)const;
    void testaIntegridadeABP(NoAB *, string&);
    void inserirBalanceado(NoAB *);
    NoAB * retirarBalanceado(NoAB *);
    void rotacaoEsquerda(NoAB *);
    void rotacaoDireita(NoAB *);
public:
    ABP();
    bool arvoreVazia () const;
    bool inserir(Item *ptrItem);
    Item * retirar(Item *);
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
        try {
            if (arvoreVazia()){
                throw string ("\nErro arovore vazia, impossivel testar a integridade da mesma");
            }
            testaIntegridadeABP(raiz, aux);
        } catch (string &erro) {
            throw erro;
        }
    }
};

#endif // ABP_H
