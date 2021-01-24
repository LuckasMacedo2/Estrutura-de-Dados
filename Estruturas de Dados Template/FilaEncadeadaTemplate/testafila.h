#ifndef TESTAFILA_H_
    #define TESTAFILA_H_
    #include <iostream>
    using std :: cout;
    using std :: cin;
    #include "fila.h"
#include<aluno.h>
class TestaFila {
    private:
        Fila<Aluno> obj;
    public:
        void mostraAluno(Aluno *);
        Aluno * criaAluno ();
        void menu();
};
#endif
