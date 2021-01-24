//#include "listaencadeada.h"

//bool ListaEncadeada::listaVazia()const{
//    return (inicio==NULL);
//}

//bool ListaEncadeada::inserirFinal(Aluno * aux){
//    if (aux==NULL){
//        return false;
//    }
//    No * novo = No::montarNo(aux);
//    if (listaVazia())
//    {
//        inicio = final = novo;
//        return true;
//    }
//    final->setProximo(novo);
//    final = novo;
//    return true;
//}

//bool ListaEncadeada::inserirInicio(Aluno * aux){
//    if (aux == NULL) return false;
//    No * novo = No::montarNo(aux);
//    if (listaVazia()){
//        inicio = final = novo;
//        return true;
//    }
//    novo->setProximo(inicio);
//    inicio = novo;
//    return true;
//}

//Aluno * ListaEncadeada::retirarInicio (){
//    if (listaVazia()) return NULL;
//    No * aux = inicio;
//    inicio = inicio->getProximo();
//    aux->setProximo(NULL);
//    if (inicio==NULL) final=NULL;
//    Aluno * retorno = aux->getDados();
//    aux->setDados(NULL);
//    delete aux;
//    return retorno;

//}

//Aluno * ListaEncadeada::buscar(std::string key) const{
//    if (listaVazia()) return NULL;
//    No * aux = inicio;

//    for (; aux !=NULL && aux->getDados()->getNome()!=key;)
//    {
//        aux = aux->getProximo();
//    }

//    if (aux==NULL) return NULL;

//    Aluno * retorno = new Aluno;
//    *retorno = *(aux->getDados());//copiando somente o conteudo não o ponteiro
//    return retorno;
//}

//Aluno * ListaEncadeada::retirar(std::string key){
//    if (listaVazia()) return NULL;
//    No * aux = inicio;
//    No * anterior = inicio;
//    while (aux!=NULL && aux->getDados()->getNome()!=key){
//        anterior = aux;
//        aux = aux->getProximo();
//    }
//    if (aux==NULL) return NULL;//Não encontrou
//    if (aux==inicio)//Primeiro No da lista
//    {
//        if (inicio==NULL) final = NULL;
//        inicio =inicio->getProximo();
//        aux->setProximo(NULL);
//    }
//    else  //Se houver 2 ou mais nós
//    {
//        if (aux==final) final = anterior;
//        anterior->setProximo(aux->getProximo());//1
//        aux->setProximo(NULL);//2
//    }
//    Aluno * retorno = aux->getDados();
//    aux->setDados(NULL);
//    delete aux;
//    return retorno;
//}

//bool ListaEncadeada::inserirOrdenado(Aluno * aux)
//{
//    if (aux==NULL) return false;
//    No * novo = No::montarNo(aux);
//    if (listaVazia()) {
//        inicio = novo; final = novo;
//        return true;
//    }
//    No * atual = inicio;
//    No * anterior = inicio;
//    while (atual != NULL && novo->getDados()->getNome() > atual->getDados()->getNome()){
//        anterior = atual;
//        atual = atual->getProximo();
//    }
//    if (atual==inicio){
//        novo->setProximo(inicio);
//        inicio = novo;
//        return true;
//    }
//    anterior->setProximo(novo);
//    novo->setProximo(atual);

//    if (atual==NULL) final = novo;
//    return true;
//}

//string ListaEncadeada::mostrar()const{
//    if (listaVazia()) return "Lista Vazia\n";
//    string saida = "";
//    No * aux = inicio;
//    while (aux!=NULL){
//        saida += "Nome: "+aux->getDados()->getNome()+"\t";
//        saida += "Matricula: " + aux->getDados()->getMatricula()+"\n";
//        aux = aux->getProximo();
//    }
//    return saida;
//}
