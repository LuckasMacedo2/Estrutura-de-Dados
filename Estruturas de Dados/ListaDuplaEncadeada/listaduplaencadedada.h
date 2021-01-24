#ifndef LISTADUPLAENCADEDADA_H
#define LISTADUPLAENCADEDADA_H
#include "no.h"

class ListaDuplaEncadedada
{
private:
    No * inicio, * fim;
public:
    ListaDuplaEncadedada ();
    bool listaVazia() const;
    bool inserirOrdenado(Contatos *aux);
    bool inserirInicio(Contatos *);
    bool inserirFinal(Contatos *);

    Contatos * retirar (std::string);
    Contatos * retirarInicio();
    Contatos * retirarFinal();

    Contatos * buscar (string )const;
    std::string listar()const;
};

#endif // LISTADUPLAENCADEDADA_H
