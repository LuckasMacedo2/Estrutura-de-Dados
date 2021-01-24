#include "item.h"
bool Item::setKey(unsigned int key){
    if (key<=0){
        return false;
    }
    this->key = key;
    return true;
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
    saida += "Key: ";
    saida += std::to_string( key);
    saida += "\t";
    saida += "Nome: ";
    saida += nome;
    return saida;
}

