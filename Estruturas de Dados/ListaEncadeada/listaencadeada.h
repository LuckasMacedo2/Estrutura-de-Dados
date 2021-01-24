#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "no.h"

class ListaEncadeada
{
private:
    No *inicio, * final;
public:
    ListaEncadeada()
    {
        inicio = final = NULL;
    }

    bool listaVazia () const;
    bool inserirFinal (Aluno *);
    bool inserirInicio (Aluno *);
    bool inserirOrdenado (Aluno *);
    Aluno * retirar (string key);
    Aluno * retirarInicio ();
    Aluno * buscar (string key)const;
    string mostrar () const;
};

#endif // LISTAENCADEADA_H
