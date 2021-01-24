#include "aluno.h"

void Aluno::setNome (string nome){
    this->nome = nome;
}

void Aluno::setMat (string mat){
    this->mat = mat;
}

string Aluno::getNome () const{
    return nome;
}
string Aluno::getMatricula () const{
    return mat;
}
