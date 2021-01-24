#include"contato.h"

void Contato::setNome (string nome){
    this->nome = nome;
}

void Contato::setTel (string tel){
    this->telefone = tel;
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
