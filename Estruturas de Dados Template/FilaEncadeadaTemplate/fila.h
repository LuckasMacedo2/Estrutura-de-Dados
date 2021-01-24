#ifndef FILA_H
#define FILA_H
template <class tipo>
class Fila {
private:
    tipo * final, * inicio;
public:
    bool enfilheirar (tipo *);
    tipo * desenfilheirar ();
    bool filaVazia () const;

    Fila ();
    ~Fila ();
};

template <class tipo>
Fila<tipo> :: Fila ()
{
    final = NULL;
    inicio = NULL;
}

template <class tipo>
bool Fila<tipo>:: filaVazia () const{
    return (inicio==NULL);//Pois nÃ£o aponta para nada
}

template <class tipo>
bool Fila<tipo>::enfilheirar(tipo * novo)
{
    if (novo==NULL)
        return false;
    novo->setProximo(NULL);
    if (filaVazia())
    {
        inicio=final=novo;
        return true;
    }
    final->setProximo(novo);
    final = novo;
    return true;
}

template <class tipo>
tipo * Fila<tipo>::desenfilheirar()
{
    if (filaVazia())
        return NULL;
    tipo * aux = inicio;
    inicio = inicio->getProximo();
    aux->setProximo(NULL);
    if (inicio==NULL)
        final = NULL;
    return aux;

}

template <class tipo>
Fila<tipo>::~Fila()
{
    tipo * aux = NULL;
    while (!filaVazia()) {
        aux = desenfilheirar();
        delete aux;
    }
}


#endif // FILA_H
