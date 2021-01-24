#ifndef LISTA_H
#define LISTA_H
#include"aluno.h"
class Lista{
private:
    Aluno **vetor;
    int tam, final;
public:
    Lista ();
    ~Lista();
    bool listaVazia()const;
    bool listaCheia()const;
    bool colocarAluno (Aluno *ptrAluno);
    Aluno * retirarAluno (int indice);
    int buscar (std::string busca);
    void setTam (int aux);
    int getFinal () const;
    void exibirLista ();
    bool inserirOrdenado (Aluno *aux);

};

#endif // LISTA_H
