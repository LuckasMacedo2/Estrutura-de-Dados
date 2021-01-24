#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "no.h"

template <class tipo>
class ListaEncadeada
{
private:
    No *inicio, * final;
public:
    ListaEncadeada()
    {
        inicio = final = NULL;
    }

    bool listaVazia () const;
    bool inserirFinal (tipo *);
    bool inserirInicio (tipo *);
    bool inserirOrdenado (tipo *);
    tipo * retirar (string key);
    tipo * retirarInicio ();
    tipo * buscar (string key)const;
    string mostrar () const;
};

template <class tipo>
bool ListaEncadeada<tipo>::listaVazia()const{
    return (inicio==NULL);
}

template <class tipo>
bool ListaEncadeada<tipo>::inserirFinal(tipo * aux){
    if (aux==NULL){
        return false;
    }
    No * novo = No::montarNo(aux);
    if (listaVazia())
    {
        inicio = final = novo;
        return true;
    }
    final->setProximo(novo);
    final = novo;
    return true;
}

template <class tipo>
bool ListaEncadeada<tipo>::inserirInicio(tipo * aux){
    if (aux == NULL) return false;
    No * novo = No::montarNo(aux);
    if (listaVazia()){
        inicio = final = novo;
        return true;
    }
    novo->setProximo(inicio);
    inicio = novo;
    return true;
}

template <class tipo>
tipo * ListaEncadeada<tipo>::retirarInicio (){
    if (listaVazia()) return NULL;
    No * aux = inicio;
    inicio = inicio->getProximo();
    aux->setProximo(NULL);
    if (inicio==NULL) final=NULL;
    tipo * retorno = aux->getDados();
    aux->setDados(NULL);
    delete aux;
    return retorno;

}

template <class tipo>
tipo * ListaEncadeada<tipo>::buscar(std::string key) const{
    if (listaVazia()) return NULL;
    No * aux = inicio;

    for (; aux !=NULL && aux->getDados()->getNome()!=key;)
    {
        aux = aux->getProximo();
    }

    if (aux==NULL) return NULL;

    tipo * retorno = new tipo;
    *retorno = *(aux->getDados());//copiando somente o conteudo não o ponteiro
    return retorno;
}

template <class tipo>
tipo * ListaEncadeada<tipo>::retirar(std::string key){
    if (listaVazia()) return NULL;
    No * aux = inicio;
    No * anterior = inicio;
    while (aux!=NULL && aux->getDados()->getNome()!=key){
        anterior = aux;
        aux = aux->getProximo();
    }
    if (aux==NULL) return NULL;//Não encontrou
    if (aux==inicio)//Primeiro No da lista
    {
        if (inicio==NULL) final = NULL;
        inicio =inicio->getProximo();
        aux->setProximo(NULL);
    }
    else  //Se houver 2 ou mais nós
    {
        if (aux==final) final = anterior;
        anterior->setProximo(aux->getProximo());//1
        aux->setProximo(NULL);//2
    }
    tipo * retorno = aux->getDados();
    aux->setDados(NULL);
    delete aux;
    return retorno;
}

template <class tipo>
bool ListaEncadeada<tipo>::inserirOrdenado(tipo * aux)
{
    if (aux==NULL) return false;
    No * novo = No::montarNo(aux);
    if (listaVazia()) {
        inicio = novo; final = novo;
        return true;
    }
    No * atual = inicio;
    No * anterior = inicio;
    while (atual != NULL && novo->getDados()->getNome() > atual->getDados()->getNome()){
        anterior = atual;
        atual = atual->getProximo();
    }
    if (atual==inicio){
        novo->setProximo(inicio);
        inicio = novo;
        return true;
    }
    anterior->setProximo(novo);
    novo->setProximo(atual);

    if (atual==NULL) final = novo;
    return true;
}

template <class tipo>
string ListaEncadeada<tipo>::mostrar()const{
    if (listaVazia()) return "Lista Vazia\n";
    string saida = "";
    No * aux = inicio;
    while (aux!=NULL){
        saida += "Nome: "+aux->getDados()->getNome()+"\t";
        saida += "Matricula: " + aux->getDados()->getMatricula()+"\n";
        aux = aux->getProximo();
    }
    return saida;
}


#endif // LISTAENCADEADA_H
