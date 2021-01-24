#include "aluno.h"

void Aluno::setNome(string nome){
    this->nome = nome;
}

void Aluno::setMat (string mat){
    this->mat = mat;
}

void Aluno::setProximo (Aluno * novo){
    this->proximo = novo;
}

string Aluno::getNome ()const{
    return nome;
}
string Aluno::getMat ()const{
    return mat;
}
Aluno * Aluno::getProximo () const{
    return proximo;
}






