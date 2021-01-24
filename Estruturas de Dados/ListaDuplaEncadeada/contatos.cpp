#include "contatos.h"
#include <iostream>
using namespace std;

void Contatos::setNome (string nome)
{
    this->nome = nome;
}

void Contatos::setEmail (string email)
{
    this->email = email;
}

void Contatos::setTel (string tel)
{
    this->telefone = tel;
}

string Contatos::getNome () const
{
    return nome;
}
string Contatos::getEmail () const
{
    return email;
}
string Contatos::getTel() const
{
    return telefone;
}
