#ifndef NO_H
#define NO_H
#include "aluno.h"

class No{
private:
    Aluno * dados;
    No * proximo;
public:
    bool setDados(Aluno *);
    void setProximo (No *);
    Aluno * getDados () const;
    No * getProximo () const;
    static No * montarNo (Aluno *); //alocar memoria, definir proximo como null, e passar os valores para os determinados dados
};

#endif // NO_H
