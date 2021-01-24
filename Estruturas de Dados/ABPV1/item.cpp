#include "item.h"
void Item::setKey (unsigned int key){
    this->key = key;
}

int Item:: getKey ()const{
    return key;
}
void Item:: setNome (string nome){
    this->nome = nome;
}

string Item:: getNome ()const{
    return nome;
}

string Item::empacotaItem () const{
    string saida("");
    saida += std::to_string( key);
    saida += "\tNome: ";
    saida += nome;
    saida += "\t";
    return saida;
}
