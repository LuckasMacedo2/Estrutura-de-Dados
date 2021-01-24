#include "aluno.h"

void Aluno :: setNome (string aux)
{
    this->nome = aux;
}

void Aluno :: setTel (string aux)
{
    this->telefone = aux;
}

void Aluno :: setMat (string aux)
{
    this->matricula = aux;
}

string Aluno :: getNome () const
{
    return nome;
}

string Aluno :: getTel () const
{
    return telefone;
}

string Aluno :: getMat () const
{
    return matricula;
}
