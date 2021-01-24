#include "No.h"

No *No::getProximo() const
{
    return proximo;
}

void No::setProximo(No *value)
{
    proximo = value;
}

Aluno No::getDados() const
{
    return dados;
}

void No::setDados(int value)
{
    dados = value;
}

void No::montarNo(int dados)
{
    this->dados = dados;
    this->setProximo(0);
}

void No::desmontarNo(No * no)
{
    no->setDados(0);
    no->setProximo(0);
    delete no;
}

No::No():
    dados(0),
    proximo(0)
{

}

No::No(No *proximo, int dados):
    dados(dados),
    proximo(proximo)
{

}
