#ifndef TESTAORDENADO_H
#define TESTAORDENADO_H
#include "listaduplaencadedada.h"

class TestaOrdenado
{
public:
    void menu ();
    void menu2();
    Contatos * criaContato ();
    void mostraContato (Contatos *) const;
};

#endif // TESTAORDENADO_H
