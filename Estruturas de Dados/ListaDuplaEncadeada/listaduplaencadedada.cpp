#include "listaduplaencadedada.h"

ListaDuplaEncadedada:: ListaDuplaEncadedada (){
    inicio = NULL;
    fim = NULL;
}

bool ListaDuplaEncadedada::listaVazia() const
{
    return (inicio==NULL);
}

bool ListaDuplaEncadedada::inserirOrdenado (Contatos * aux)
{
    try {
        if (aux==NULL)
            return false;

        No * novo = No::montarNo(aux);
        if(listaVazia()){
            inicio=novo;
            fim=novo;
            return true;
        }
        No * atual = inicio;
        No * ant = inicio;
        while (atual !=NULL &&  novo->getDados()->getNome() > atual->getDados()->getNome()) {
            ant = atual;
            atual = atual->getProximo();
        }
        if(atual==inicio){
            novo->setProximo(inicio);
            inicio->setAnterior(novo);
            inicio=novo;
            return true;
        }
        if(atual==NULL){
            fim=novo;
            fim->setProximo(atual);
            fim->setAnterior(ant);
            ant->setProximo(fim);

        }
        else{
            ant->setProximo(novo);
            atual->setAnterior(novo);
            novo->setAnterior(ant);
            novo->setProximo(atual);
        }
        return true;
    } catch (std::bad_alloc &) {
       throw string ("\nFalta de memoria\n");
    }
}
bool ListaDuplaEncadedada::inserirInicio(Contatos *aux){
    try {
        if (aux==NULL)
            return false;
        No *novo=No::montarNo(aux);
        if (listaVazia())
        {
            inicio=novo;
            fim=novo;
            novo->setAnterior(NULL);
            novo->setProximo(NULL);
            return true;
        }
        inicio->setAnterior(novo);
        novo->setProximo(inicio);
        inicio=novo;
        inicio->setAnterior(NULL);
        return true;
    } catch (std::bad_alloc &) {
        throw string ("\nFalta de memoria\n");
    }
}

bool ListaDuplaEncadedada::inserirFinal (Contatos * aux)
{
    try {
        if (aux==NULL)
            return false;
        No *novo=No::montarNo(aux);
        if (listaVazia())
        {
            inicio=novo;
            fim=novo;
            novo->setAnterior(NULL);
            novo->setProximo(NULL);
            return true;
        }
        fim->setProximo(novo);
        novo->setAnterior(fim);
        fim=novo;
        fim->setProximo(NULL);
        return true;
    } catch (std::bad_alloc &) {
        throw string ("\nFalta de memoria\n");
    }
}

Contatos * ListaDuplaEncadedada::retirarInicio(){
        if(listaVazia())
            throw string ("\nERRO. A lista encontra-se vazia, impossivel remover o contato\n");
        No *aux= inicio;

        inicio = inicio->getProximo();
        if (inicio==NULL)
            fim = NULL;
        else
            inicio->setAnterior(NULL);

        aux->setProximo(NULL);
        Contatos *retorno=aux->getDados();
        aux->setDados(NULL);
        return retorno;

}

Contatos * ListaDuplaEncadedada::retirarFinal(){
    if(listaVazia())
        throw string ("\nERRO. A lista encontra-se vazia impossivel remover o contato\n");

    No *aux=fim;
    if (fim==inicio){
        Contatos * p=new Contatos;
        p=fim->getDados();
        fim=NULL;
        inicio=NULL;
        return p;
    }
    fim=fim->getAnterior();
    fim->setProximo(NULL);
    Contatos *retorno=aux->getDados();
    return retorno;
}

Contatos *ListaDuplaEncadedada:: retirar (std::string key)
{
    if (listaVazia())
        throw string ("\nERRO. A lista encontra-se vazia, impossivel remover.\n");

    No * aux = inicio;
    No * ant = inicio;

    while (aux!=NULL && aux->getDados()->getNome()!=key){
        ant = aux;
        aux = aux->getProximo();
    }

    if (aux==NULL)
        return NULL;

    if (aux==inicio)
    {
        if (inicio==NULL) //se houver apenas um elemento na lista
            fim = NULL;
        inicio = inicio->getProximo();
        aux->setProximo(NULL);
        aux->setAnterior(NULL);
    }

    else  //Se houver 2 ou mais nós
    {
        if (aux==fim) {
            fim = ant;
            fim->setProximo(NULL);
        }
        else{
        aux->getProximo()->setAnterior(aux->getAnterior());
        aux->getAnterior()->setProximo(aux->getProximo());
        aux->setProximo(NULL);
        aux->setAnterior(NULL);
        }
    }

    Contatos * retorno = aux->getDados();

    aux->setDados(NULL);

    delete aux;
    return retorno;
}

Contatos *ListaDuplaEncadedada:: buscar (string key)const
{
    if (listaVazia())
        throw string ("\nERRO. A lista encontrasse vazia\n");

    No * aux = inicio;

    for (; aux !=NULL && aux->getDados()->getNome() !=key;)
    {
         aux = aux->getProximo();
    }

    if (aux==NULL) return NULL;
    Contatos * retorno = new Contatos;
    *retorno = *(aux->getDados());//copiando somente o conteudo não o ponteiro
    return retorno;
}

string ListaDuplaEncadedada::listar()const
{
    if(listaVazia())
        throw string ("\nERRO. Lista vazia\n");
    string res="";
    No *aux=inicio;
    while(aux != NULL){
        res += "Nome: " + aux->getDados()->getNome() +"\t";
        res +="fone: "+ aux->getDados()->getTel() +"\t";
        res +="email: "+ aux->getDados()->getEmail() +"\n";
        aux = aux->getProximo();
    }
    return res;
}
