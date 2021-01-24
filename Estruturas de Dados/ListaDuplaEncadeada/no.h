#ifndef NO_H
#define NO_H
#include "contatos.h"

class No
{
private:
    No * anterior, * proximo;
    Contatos * dados;
public:
    No();
    void setAnterior (No *);
    void setProximo (No *);
    bool setDados(Contatos *);
    No * getAnterior () const;
    No * getProximo () const;
    Contatos *getDados() const;

    static No* montarNo (Contatos * aux);
    Contatos * desmontarNo (No *);

};

#endif // NO_H
