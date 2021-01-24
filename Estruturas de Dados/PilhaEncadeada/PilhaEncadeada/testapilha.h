#ifndef TESTAPILHA_H
#define TESTAPILHA_H

#include "pilha.h"

class TestaPilha{
private:
    Pilha obj;

public:

    Contato * criarContato ();
    void mostrarContato (Contato *);

    void menu ();
};



#endif // TESTAPILHA_H
