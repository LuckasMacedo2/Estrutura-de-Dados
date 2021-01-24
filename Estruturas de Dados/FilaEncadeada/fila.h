#ifndef FILA_H
#define FILA_H
#include "aluno.h"
class Fila {
private:
    Aluno * final, * inicio; //Está usando somente no escopo da fila
public:
    bool enfilheirar (Aluno *);
    Aluno * desenfilheirar ();
    bool filaVazia () const;

    Fila ();
    ~Fila ();
};

#endif // FILA_H
