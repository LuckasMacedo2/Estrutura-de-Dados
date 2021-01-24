#include "noab.h"

NoAB::NoAB()
{
    pai = NULL;
    esquerda = NULL;
    direita = NULL;
    dados = NULL;
}

void NoAB::setPai (NoAB * pai){
    this->pai = pai;
}

void NoAB::setEsquerda (NoAB * esquerda){
    this->esquerda = esquerda;
}
void NoAB::setDireita (NoAB * direita){
    this->direita = direita;
}

void NoAB::setDados (Item * aux){
    try {
//       if (!aux){
//           throw string ("\nErro, objeto invalido");
//       }
       dados = aux;
    } catch (string &erro) {
        throw (erro);
    }
}

NoAB * NoAB::getPai () const{
    return pai;
}
NoAB * NoAB::getEsquerda () const{
    return esquerda;
}
NoAB * NoAB::getDireita () const{
    return direita;
}
Item * NoAB::getDados () const{
    return dados;
}

NoAB * NoAB:: montarNo (Item * aux){
    try {

        NoAB * no = new NoAB;
        no->setDireita(NULL);
        no->setEsquerda(NULL);
        no->setPai(NULL);
        no->setDados(aux);
        return no;
    } catch (std::bad_alloc &) {
        throw string ("\nErro, memoria para armazenamento insuficiente");
    }
}

Item * NoAB::desmontarNo (NoAB * no){
    try {
        if (!no)
            throw string ("\nErro, objeto informado invalido");
        Item * aux = no->getDados();
        no->setDados(NULL);
        delete no;
        return aux;
    } catch (string &erro){
        throw (erro);
    }
}
