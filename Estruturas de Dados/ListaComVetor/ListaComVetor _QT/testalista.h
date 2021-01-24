#ifndef TESTALISTA_H
#define TESTALISTA_H
#include "lista.h"
class TestaLista{
private:
    Aluno *vetor;
    Lista obj;
public:
    Aluno * criarAluno ();
    void mostraAluno (Aluno *aux);
    void menu();

};

#endif // TESTALISTA_H
