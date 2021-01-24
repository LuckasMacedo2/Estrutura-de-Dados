#include "aluno.h"

void Aluno::setNome (string aux){
    this->nome=aux;
}

void Aluno::setMat (string aux){
    this->mat = aux;
}

void Aluno::setTel (string aux){
    this->tel = aux;
}

string Aluno::getNome()const{
    return nome;
}
string Aluno::getMat () const{
    return mat;
}
string Aluno::getTel () const{
    return tel;
}
