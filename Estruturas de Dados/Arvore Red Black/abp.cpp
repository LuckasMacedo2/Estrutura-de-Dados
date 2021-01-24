#include "abp.h"
#include <iostream>
using namespace std;
ABP::ABP()
{
    try {
        nulo = new NoAB;
        nulo->setCor(0);
        raiz = nulo;
        raiz->setCor(0);
    } catch (std::bad_alloc &) {
        throw string ("\nErro, falta de memoria");
    }
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
            novo->setCor(0);
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
        inserirBalanceado(novo);
        return true;
    } catch (string &erro) {
        throw erro;
    }
}

void ABP::inserirBalanceado(NoAB * t)
{
    try {
        NoAB * u;
        if (raiz==t){
            t->setCor(0);
            return;
        }
        while(t->getPai() != nulo && t->getPai()->getCor() == 1 && t->getPai()->getCor() == 1){
            NoAB * g = t->getPai()->getPai();
            if (g->getEsquerda() == t->getPai()){
                u = g->getDireita();
                if (u->getCor() == 1 && u != nulo){
                    t->getPai()->setCor(0);
                    u->setCor(0);
                    g->setCor(1);
                    t = g;
                }
                else{
                    if (t->getPai()->getDireita() == t){
                        rotacaoEsquerda(t->getPai());
                        t = t->getPai();
                    }
                    rotacaoDireita(g);
                    NoAB aux;
                    aux.setCor(t->getPai()->getCor());
                    t->getPai()->setCor(g->getCor());
                    g->setCor(aux.getCor());
                    t = t->getPai();
                }
            }
            else
            {
                u = g->getEsquerda();
                if (u->getCor() == 1 && u!=nulo){
                    t->getPai()->setCor(0);
                    u->setCor(0);
                    g->setCor(1);
                    t = g;
                }
                else
                {
                    if (t->getPai()->getEsquerda() == t){
                        rotacaoDireita(t->getPai());
                        t = t->getPai();
                    }
                    rotacaoEsquerda(g);

                    NoAB aux;
                    aux.setCor(t->getPai()->getCor());
                    t->getPai()->setCor(g->getCor());
                    g->setCor(aux.getCor());
                    t = t->getPai();
                }
            }
            raiz->setCor(0);
        }
    } catch (string &erro) {
        throw (erro);
    }
}

Item * ABP::retirar (Item *obj){
    try {
        if(arvoreVazia()) throw string("\n Erro, arvore vazia impossivel remover o item\n");
        NoAB *z =busca(obj);
        if(z==nulo)
            throw string("\nErro, item nao se encontra na arvore\n");

        Item *obj=new Item;
        *obj=*z->getDados();
        NoAB * x=nulo,* y=nulo;
        NoAB * aux = nulo;

        if(z->getDireita() == nulo || z->getEsquerda() ==nulo){
            y=z;
        }
        else {
            y=sucessor(z);
        }

        if(y->getEsquerda()!=nulo){
            x=y->getEsquerda();
        }
        else{
            x=y->getDireita();
        }
        //if(x!=nulo){
            x->setPai(y->getPai());
        //}
        if(y->getPai()==nulo){
            raiz=x;
        }
        else{
            if(y==y->getPai()->getEsquerda()){
                y->getPai()->setEsquerda(x);
            }
            else {
                y->getPai()->setDireita(x);
            }

        }
        if(y!=z){
            *z->getDados()=*y->getDados();
        }
        if(y->getCor()==0){
            retirarBalanceado(x);
        }
        delete y;
        return obj;
    } catch (string &erro) {
        throw erro;
    }

}


NoAB *ABP::retirarBalanceado(NoAB *p)
{
    try {
        //        NoAB * irmao;
        //        /*Exclusão do tipo caso 1*/
        //        if (p->getPai()!=nulo){
        //            /*Exclusão do tipo caso 2*/
        //            if (p == p->getPai()->getEsquerda())
        //                irmao = p->getPai()->getDireita();
        //            else
        //                irmao = p->getPai()->getEsquerda();

        //            if (irmao->getCor()==1){
        //                p->getPai()->setCor(1);
        //                irmao->setCor(0);
        //                if (p->getPai()->getEsquerda() == p)
        //                    rotacaoEsquerda(p->getPai());
        //                else
        //                    rotacaoDireita(p->getPai());
        //            }
        //            /*Exclusão do tipo caso 3*/
        //            if (p == p->getPai()->getEsquerda())
        //                irmao = p->getPai()->getDireita();
        //            else
        //                irmao = p->getPai()->getEsquerda();
        //            //NoAB * irmao;
        //            if (p->getPai()->getCor() == 0 && irmao->getCor() == 0 &&
        //                    irmao->getEsquerda()->getCor() == 0 && irmao->getDireita()->getCor() == 0){
        //                irmao->setCor(1);
        //            }else{
        //                /*Exclusão do tipo caso 4*/
        //                //NoAB * irmao;
        //                if (p == p->getPai()->getEsquerda())
        //                    irmao = p->getPai()->getDireita();
        //                else
        //                    irmao = p->getPai()->getEsquerda();

        //                if (p->getPai()->getCor() == 1 && irmao->getCor() == 0
        //                        &&irmao->getEsquerda()->getCor()==0 && irmao->getDireita()->getCor() == 0){
        //                    irmao->setCor(1);
        //                    p->getPai()->setCor(0);
        //                }
        //                else{
        //                    /*Exclusão do tipo caso 5*/
        //                    //NoAB * irmao;
        //                    if (p == p->getPai()->getEsquerda())
        //                        irmao = p->getPai()->getDireita();
        //                    else
        //                        irmao = p->getPai()->getEsquerda();

        //                    if (irmao->getCor() == 0)
        //                    {
        //                        if(p == p->getPai()->getEsquerda() && irmao->getDireita()->getCor() == 0 &&
        //                                irmao->getEsquerda()->getCor()==1){
        //                            irmao->setCor(1);
        //                            irmao->getEsquerda()->setCor(0);
        //                            rotacaoDireita(irmao);
        //                        }
        //                        else{
        //                            if (p == p->getPai()->getDireita() && irmao->getEsquerda()->getCor() == 0 &&
        //                                    irmao->getDireita()->getCor()==1) {
        //                                irmao->setCor(1);
        //                                irmao->getDireita()->setCor(1);
        //                                rotacaoEsquerda(irmao);
        //                            }
        //                        }
        //                    }
        //                    /*Exclusão do tipo caso 6*/
        //                    if (p == p->getPai()->getEsquerda())
        //                        irmao = p->getPai()->getDireita();
        //                    else
        //                        irmao = p->getPai()->getEsquerda();

        //                    irmao->setCor(p->getPai()->getCor());
        //                    p->getPai()->setCor(0);

        //                    if(p == p->getPai()->getEsquerda()){
        //                        irmao->getDireita()->setCor(0);
        //                        rotacaoEsquerda(p->getPai());
        //                    }
        //                    else{
        //                        irmao->getEsquerda()->setCor(0);
        //                        rotacaoDireita(p->getPai());
        //                    }
        //                }
        //            }
        //        }



        NoAB *s;
        while(p!=raiz && p->getCor()==0)
        {
            if(p->getPai()!=nulo){
                if(p->getPai()->getEsquerda()==p)
                {
                    s=p->getPai()->getDireita();
                    if(s->getCor()==1)
                    {
                        s->setCor(0);
                        p->getPai()->setCor(1);
                        rotacaoEsquerda(p->getPai());
                        s=p->getPai()->getDireita();
                    }
                    if(s->getDireita()->getCor()==0 && s->getEsquerda()->getCor()==0)
                    {
                        s->setCor(1);
                        p=p->getPai();
                    }
                    else
                    {
                        if(s->getDireita()->getCor()==0)
                        {
                            s->getEsquerda()->setCor(0);
                            s->setCor(1);
                            rotacaoDireita(s);
                            s=p->getPai()->getDireita();
                        }
                        s->setCor(p->getPai()->getCor());
                        p->getPai()->setCor(0);
                        s->getDireita()->setCor(0);
                        rotacaoEsquerda(p->getPai());
                        p=raiz;
                    }
                }
                else
                {
                    s=p->getPai()->getEsquerda();

                    if(s->getCor()==1)
                    {
                        s->setCor(0);
                        p->getPai()->setCor(1);
                        rotacaoDireita(p->getPai());
                        s=p->getPai()->getEsquerda();
                    }
                    if(s->getEsquerda()->getCor()==0 && s->getDireita()->getCor() ==0)
                    {
                        s->setCor(1);
                        p=p->getPai();
                    }
                    else
                    {
                        if(s->getEsquerda()->getCor()==0)
                        {
                            s->getDireita()->setCor(0);
                            s->setCor(1);
                            rotacaoEsquerda(s);
                            s=p->getPai()->getEsquerda();
                        }
                        s->setCor(p->getPai()->getCor());
                        p->getPai()->setCor(0);
                        s->getEsquerda()->setCor(0);
                        rotacaoDireita(p->getPai());
                        p=raiz;
                    }
                }
                raiz->setCor(0);
            }
        }

    } catch (string &erro) {
        throw erro;
    }
}
//Sucessor: nó mais proximo e menor que o nó passado como parametro, seja é
//o nó que mais se aproxima do nó passado, ou seja é o menor nó do lado direto
//se o nó não tiver filho a direita e ser filho a direita o mesmo não possui sucessor
NoAB * ABP::sucessor(NoAB * aux){
    if (aux==nulo){
        return nulo;
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
void ABP::rotacaoEsquerda(NoAB * p)
{
    try {
        if (p->getDireita()==nulo){
            return;
        }
        else{
            NoAB * y = p->getDireita();
            if(y->getEsquerda() !=nulo){
                p->setDireita(y->getEsquerda());
                y->getEsquerda()->setPai(p);
            }else{
                p->setDireita(nulo);
            }
            if (p->getPai()!=nulo){
                y->setPai(p->getPai());
            }
            if (p->getPai() == nulo){
                raiz = y;
                raiz->setPai(nulo);
            }
            else{
                if (p == p->getPai()->getEsquerda()){
                    p->getPai()->setEsquerda(y);
                }
                else
                {
                    p->getPai()->setDireita(y);
                }
            }
            y->setEsquerda(p);
            p->setPai(y);
        }
    } catch (string &erro) {
        throw (erro);
    }
}

void ABP::rotacaoDireita(NoAB * p)
{
    try {
        if (p->getEsquerda() == nulo){
            return;
        }
        else{
            NoAB * y = p->getEsquerda();
            if (y->getDireita() != nulo){
                p->setEsquerda(y->getDireita());
                y->getDireita()->setPai(p);
            }
            else{
                p->setEsquerda(nulo);
            }
            if (p->getPai()!=nulo){
                y->setPai(p->getPai());
            }
            if (p->getPai() == nulo){
                raiz = y;
                raiz->setPai(nulo);
            }
            else{
                if (p == p->getPai()->getEsquerda())
                    p->getPai()->setEsquerda(y);
                else
                    p->getPai()->setDireita(y);
            }
            y->setDireita(p);
            p->setPai(y);
        }
    } catch (string &erro) {
        throw (erro);
    }
}


NoAB * ABP::minimo(NoAB * aux){
    if (aux==nulo){
        return nulo;
    }
    NoAB * min = aux;
    while (min->getEsquerda() != nulo) {
        min = min->getEsquerda();
    }
    return min;
}

NoAB * ABP::maximo(NoAB * aux){
    if (aux==nulo){
        return nulo;
    }
    NoAB * max = aux;
    while (max->getDireita()!= nulo){
        max = max->getDireita();
    }
    return max;
}

//Antecessor: nó mais proximo e menor que o nó passado como parametro
//Se chegar na raiz o nó não apresenta antecessor, condições de desvio
//se chegar na raiz, e o pai for nulo
NoAB * ABP::antecessor(NoAB * aux){
    if (aux==nulo){
        return nulo;
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
}


Item * ABP::pesquisar(Item * busca) const{
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
    if (pNo->getCor() == 0)
        saida += "\nCor: Preto";
    else
        saida += "\nCor: vermelho";
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


















/* NoAB * aux = NoAB::montarNo(item);
 if (aux->getPai()->getEsquerda() == aux){
     aux->getPai()->setEsquerda (nulo);
     aux->setPai(nulo);
     Item * ret = NoAB::desmontaNo (aux);
     return ret;
 }
 else{
     aux->getPai->setDireita(nulo);
     aux->setPai(nulo);
     Item * ret = NoAB::desmontaNo (aux);
     return ret;
 }

 if (aux->getDireita()==nulo || aux->getEsquerda()==nulo){
     NoAB * ant = aux;
     if (aux->getDireita()==nulo){
        aux = aux->getDireita();
        aux->setPai(ant->getPai());
        delete ant;
        Item * ret = NoAB::desmontarNo(aux);
        return ret;
     }
     else{
         aux = aux->getEsquerda();
         aux->setPai(ant->getPai());
         delete ant;
         Item * ret = NoAB::desmontarNo(aux);
         return ret;
     }
 }*/



