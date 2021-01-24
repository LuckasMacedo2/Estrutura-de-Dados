#ifndef PILHA_H
#define PILHA_H
#include "livro.h"

#endif // PILHA_H
class Pilha {
    private:
        livro **vet; //vetor que armazena o endereço de outro vetor
        short int topo, tam;
    public:
       Pilha();
       ~Pilha();
       bool push (livro*);//coloca na pilha
       livro * pop();//retira da pilha
       bool pilhaVazia()const;
       bool pilhaCheia()const;
       bool setTamanho(short int);//define o tamanho e aloca vet
       short int getTamanho ()const;//retorna o tamanho

};
