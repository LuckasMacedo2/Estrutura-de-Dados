#ifndef FILA_H_
    #define FILA_H_

#include "aluno.h"
class Fila {
    private:
        Aluno **vet;
        int tam, final;
    public:
        Fila();
        ~Fila();
        bool filaVazia ()const;
        bool filaCheia ()const;
        Aluno * desenfilheirar ();
        bool enfilheirar (Aluno *);
        bool setTam (int);
        int getTam () const;

};

#endif
