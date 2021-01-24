#include "no.h"

bool No::setDados(Aluno * aux){
    if (aux){
        dados = aux;
        return true;
    }
    return false;
}

Aluno * No::getDados()const{
    return dados;
}

void No::setProximo(No * aux){
    proximo = aux;
}

No * No::getProximo()const{
    return proximo;
}

No * No::montarNo(Aluno * aux){
    No * novo = new No;
    novo->setDados(aux);
    novo->setProximo(NULL);
    return novo;
}
