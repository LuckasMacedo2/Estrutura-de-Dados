#include "abp.h"

ABP::ABP()
{
    raiz = nulo;
}

bool ABP::arvoreVazia() const
{
    if(raiz==nulo)
        return true;
    return false;
}

bool ABP::inserir(Item * ptrItem){
    try {
        if (!ptrItem)
            throw string ("\nErro, impossivel inserir o objeto informado");
        NoAB * novo = NoAB::montarNo (ptrItem);
        novo->setEsquerda(nulo);
        novo->setDireita(nulo);
        if (arvoreVazia()){
            raiz=novo;
            novo->setPai(nulo);
            return  true;
        }
        NoAB * anterior = raiz;
        NoAB * auxiliar = raiz;
        while (auxiliar!=nulo){
            if (novo->getDados()->getKey() < auxiliar->getDados()->getKey()){
                anterior = auxiliar;
                auxiliar = auxiliar->getEsquerda();
            }
            else{
                if (novo->getDados()->getKey() > auxiliar->getDados()->getKey()){
                    anterior = auxiliar;
                    auxiliar =auxiliar->getDireita();
                }
                else{
                    ptrItem = NoAB::desmontarNo(novo);
                    return false;
                }
            }
        }
        novo->setPai(anterior);
        if (novo->getDados()->getKey() < anterior->getDados()->getKey()){
            anterior->setEsquerda(novo);
        }
        else
        {
            anterior->setDireita(novo);
        }
        return true;
    } catch (string &erro) {
        throw erro;
    }
}


NoAB * ABP::minimo(NoAB * aux){
    try {
        if (aux==nulo){
            throw string ("\nErro, objeto informado inválido");
        }
        NoAB * min = aux;
        while (min->getEsquerda() != nulo) {
           min = min->getEsquerda();
        }
        return min;
    } catch (string &erro) {
        throw erro;
    }
}

NoAB * ABP::maximo(NoAB * aux){
    try {
        if (aux==nulo){
            throw string ("\nErro, objeto informado inválido");
        }
        NoAB * max = aux;
        while (max->getDireita()!= nulo){
            max = max->getDireita();
        }
        return max;
    } catch (string &erro) {
        throw erro;
    }
}

//Antecessor: nó mais proximo e menor que o nó passado como parametro
//Se chegar na raiz o nó não apresenta antecessor, condições de desvio
//se chegar na raiz, e o pai for nulo
NoAB * ABP::antecessor(NoAB * aux){
    try {
        if (aux==nulo){
            throw string ("\nErro, objeto informado inválido");
        }
        NoAB * ant = aux;
        if (ant->getEsquerda()!=nulo){
            return maximo(ant->getEsquerda());
        }
        while (ant->getPai() != nulo){
            if (ant->getPai()->getDireita()==ant){
                return ant->getPai();
            }
            else{
                ant = ant->getPai();
            }
        }
        return nulo;
    } catch (string &erro) {
        throw erro;
    }
}

//Sucessor: nó mais proximo e menor que o nó passado como parametro, seja é
//o nó que mais se aproxima do nó passado, ou seja é o menor nó do lado direto
//se o nó não tiver filho a direita e ser filho a direita o mesmo não possui sucessor
NoAB * ABP::sucessor(NoAB * aux){
    try {
        if (aux==nulo){
            throw string ("\nErro, objeto informado inválido");
        }
        NoAB * ant = aux;
        if (ant->getDireita()!=nulo){
            return minimo(ant->getDireita());
        }
        while (ant->getPai() != nulo){
            if (ant->getPai()->getEsquerda()==ant){
                return ant->getPai();
            }
            else{
                ant = ant->getPai();
            }
        }
        return nulo;
    } catch (string &erro) {
        throw erro;
    }
}

Item * ABP::pesquisar(Item * busca) const{
    try {
        if (arvoreVazia())
            throw string ("\nErro, impossivel pesquisar em uma arvore vazia");
        NoAB * aux = raiz;
        NoAB * pNo = NoAB::montarNo (busca);
        while (aux != nulo){
            if (pNo->getDados()->getKey() < aux->getDados()->getKey()){
                aux = aux->getEsquerda();
            }
            else {
                if (pNo->getDados()->getKey() > aux->getDados()->getKey()){
                    aux = aux->getDireita();
                }
                else{
                    busca = NoAB::desmontarNo(pNo);
                    *busca = *aux->getDados();
                    return busca;
                }
            }
        }
        busca = NoAB::desmontarNo(pNo);
        delete busca;
        busca = 0;
        return busca;
    } catch (string &erro) {
        throw erro;
    }
}

NoAB * ABP:: busca (Item * busca) const
{
    try {
        if (arvoreVazia())
            throw ("\nErro, a arvore encontra-se vazia, impossivel realizar a operação");
        NoAB * aux = raiz;
        NoAB * pNo = NoAB::montarNo (busca);
        while (aux != nulo){
            if (pNo->getDados()->getKey() < aux->getDados()->getKey()){
                aux = aux->getEsquerda();
            }
            else {
                if (pNo->getDados()->getKey() > aux->getDados()->getKey()){
                    aux = aux->getDireita();
                }
                else{
                    busca = NoAB::desmontarNo(pNo);
                    delete busca;
                    return aux;
                }
            }
        }
        busca = NoAB::desmontarNo(pNo);
        delete busca;
        return nulo;
    } catch (string &erro) {
        throw erro;
    }
}

Item * ABP::retirar (Item *obj){
    try {
        if (arvoreVazia())
            throw string ("\nArvore vazia, impossivel remover qualquer nó");
        NoAB * z = busca(obj);
        if (z == nulo){
            //O objeto passado não foi encontrado
            delete obj; //liberou a memoria que estava sendo usada pelo mesmo
            throw string ("\nErro, objeto não foi encontrado!");
        }

        Item * ret = new Item;//copia
        * ret = *z->getDados();
        NoAB * x = nulo;
        NoAB * y = nulo;

        //Definindo a variavel auxiliar y
        if (z->getDireita() == nulo || z->getEsquerda() == nulo)    //O nó z tem nenhum ou 1 filho
        {
            y = z;
        }
        else{   //O nó z apresenta dois filhos, tanto esquerda quanto direita
            y = sucessor(z);
        }

        //Definindo a variavel auxiliar x
        if (y->getEsquerda()!=nulo){
            x = y->getEsquerda();
        }
        else{
            x = y->getDireita();
        }

        if (x!=nulo){
            x->setPai(y->getPai());
        }

        if (y->getPai()==nulo){
            raiz = x;
        }
        else{
            if (y == y->getPai()->getEsquerda()){
                y->getPai()->setEsquerda(x);//O x é filho a esquerda do pai
            }
            else{
                y->getPai()->setDireita(x);
            }
        }
        if (y!=z){//quando o nó y apresentar um filho ou dois filhos, ou seja y não é nó folha
            *z->getDados() = *y->getDados(); //copiando o conteudo
       }
        delete y;   // As ligações já foram refeitas
        return ret;
    } catch (string &erro) {
        throw erro;
    }
}

void ABP::imprimirPreOrdem (NoAB * aux, string &ret) const{
    if (aux==nulo){
        return;
    }
    ret = ret + aux->getDados()->empacotaItem();
    imprimirPreOrdem(aux->getEsquerda(),ret);
    imprimirPreOrdem(aux->getDireita(),ret);
}

void ABP::imiprimirEmOrdem(NoAB * aux, std::string &ret) const{
    if (aux==nulo){
        return;
    }
    imiprimirEmOrdem (aux->getEsquerda(), ret);
    imiprimirEmOrdem (aux->getDireita(), ret);
    ret = ret + aux->getDados()->empacotaItem();
}

void ABP:: imprimirPosOrdem (NoAB * aux, string & ret)const{
    if (aux==nulo){
        return;
    }
    imprimirPosOrdem(aux->getEsquerda(),ret);
    imprimirPosOrdem(aux->getDireita(),ret);
    ret = ret + aux->getDados()->empacotaItem();
}

void ABP::testaIntegridadeABP(NoAB * pNo, std::string & saida)  //
{
    if (pNo==nulo){
        return;
    }
    saida += "\nNo -> " + pNo->getDados()->empacotaItem();
    if (pNo->getPai() != nulo)
        saida += "\nFilho de " + std::to_string(pNo->getPai()->getDados()->getKey());
    else
        saida += "\nNao possui pai";
    if (pNo->getEsquerda() != nulo)
        saida += "\nPai a esquerda de " + std::to_string(pNo->getEsquerda()->getDados()->getKey());
    else
        saida += "\nNao possui filho a esquerda";
    if (pNo->getDireita()!=nulo)
        saida += "\nPai a direita de " + std::to_string(pNo->getDireita()->getDados()->getKey());
    else
        saida += "\nNao possui filho a direita";
    saida += "\n";
    if (pNo->getEsquerda()!=nulo)
    {
        if (pNo->getEsquerda()->getDados()->getKey() > pNo->getDados()->getKey()){
            saida = saida + "\nErro: filho da esquerda maior que pai\n";
            saida = saida + std::to_string(pNo->getDados()->getKey()) + "\n";
            saida = saida + pNo->getEsquerda()->getDados()->empacotaItem() + "\n";
        }
    }
    if (pNo->getDireita() != nulo){
        if (pNo->getDireita()->getDados()->getKey() < pNo->getDados()->getKey()){
            saida = saida + "\nErro: filho da direita menor que pai\n";
            saida = saida + std::to_string(pNo->getDados()->getKey()) + "\n";
            saida = saida + pNo->getEsquerda()->getDados()->empacotaItem() + "\n";
        }
    }
    testaIntegridadeABP(pNo->getEsquerda(),saida);
    testaIntegridadeABP(pNo->getDireita(),saida);

}
