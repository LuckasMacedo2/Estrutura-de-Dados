#include "no.h"
No::No(){
   anterior = NULL;
   proximo = NULL;
}

void No::setAnterior (No * aux){
    anterior = aux;
}

void No::setProximo (No * aux)
{
    proximo = aux;
}

bool No::setDados (Contatos * aux)
{
   if (aux){
     dados = aux;
     return true;
   }
   return false;

}

No * No::getAnterior () const
{
    return anterior;
}

No * No::getProximo () const
{
    return proximo;
}

Contatos * No::getDados () const
{
    return dados;
}

No *No::montarNo(Contatos * aux)
{
    No * novo = new No;
    novo->setDados(aux);
    novo->setProximo(NULL);
    novo->setAnterior(NULL);
    return novo;
}

Contatos * No::desmontarNo (No * aux)
{
   Contatos * rt = aux->getDados();
   aux->setDados(NULL);
   delete aux;
   return rt;
}
