#include"contato.h"

void Contato::setNome (string set){
    this->nome = set;
}

void Contato::setTel (string set){
    this->telefone = set;
}

string Contato::getNome () const{
    return nome;
}
string Contato::getTel () const{
   return telefone;
}
void Contato::setProximo (Contato *aux){
    this->proximo = aux;
}

Contato * Contato::getProximo () const{
    return proximo;
}
Contato::Contato (){
    proximo = 0;

}
