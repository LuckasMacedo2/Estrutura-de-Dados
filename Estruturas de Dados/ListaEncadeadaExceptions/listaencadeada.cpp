#include "listaencadeada.h"

bool ListaEncadeada::listaVazia()const{
    return (inicio==NULL);
}

void ListaEncadeada::inserirFinal(Aluno * aux){
    if (aux==NULL){
        throw string ("\nImpossivel realizar a operação\n");
    }
    No * novo = No::montarNo(aux);
    if (listaVazia())
    {
        inicio = final = novo;
    }
    final->setProximo(novo);
    final = novo;
}

void ListaEncadeada::inserirInicio(Aluno * aux){
    if (aux == NULL)
    {
        throw string ("\nImpossivel realizar a operação\n");
    }
    No * novo = No::montarNo(aux);
    if (listaVazia()){
        inicio = final = novo;
    }
    novo->setProximo(inicio);
    inicio = novo;
    try {
    } catch (string &erro) {
        throw string ("\nErro, impossivel inserir aluno no inicio da lista");
    }
}

Aluno * ListaEncadeada::retirarInicio (){
    if (listaVazia())
    {
        throw string ("\nImpossivel realizar a operação\n");
    }
    No * aux = inicio;
    inicio = inicio->getProximo();
    aux->setProximo(NULL);
    if (inicio==NULL) final=NULL;
    Aluno * retorno = aux->getDados();
    aux->setDados(NULL);
    delete aux;
    return retorno;

}

Aluno * ListaEncadeada::buscar(std::string key) const{
    if (listaVazia())
    {
       throw string ("\nImpossivel realizar a operação\n");
    }
    try {
        No * aux = inicio;

        for (; aux !=NULL && aux->getDados()->getNome()!=key;)
        {
            aux = aux->getProximo();
        }

        if (aux==NULL) return NULL;

        Aluno * retorno = new Aluno;
        *retorno = *(aux->getDados());//copiando somente o conteudo não o ponteiro
        return retorno;
    } catch (string &erro) {
        throw string ("\nErro, impossivel buscar pelo aluno.");
    }
}

Aluno * ListaEncadeada::retirar(std::string key){
    if (listaVazia()) 
    {
       throw string ("\nImpossivel realizar a operação\n"); 
    }
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
    Aluno * retorno = aux->getDados();
    aux->setDados(NULL);
    delete aux;
    return retorno;

}

void ListaEncadeada::inserirOrdenado(Aluno * aux)
{
    if (aux==NULL)
    {
        throw string ("\nImpossivel realizar a operação\n");
    }
    No * novo = No::montarNo(aux);
    if (listaVazia()) {
        inicio = novo; final = novo;
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
    }
    anterior->setProximo(novo);
    novo->setProximo(atual);

    if (atual==NULL) final = novo;
}

string ListaEncadeada::mostrar()const{
    if (listaVazia()) throw string("Lista Vazia\n");
    string saida = "";
    No * aux = inicio;
    while (aux!=NULL){
        saida += "Nome: "+aux->getDados()->getNome()+"\t";
        saida += "Matricula: " + aux->getDados()->getMatricula()+"\n";
        aux = aux->getProximo();
    }
    return saida;
}
