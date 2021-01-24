//#include "fila.h"
//Fila :: Fila ()
//{
//    final = NULL;
//    inicio = NULL;
//}

//bool Fila:: filaVazia () const{
//    return (inicio==NULL);//Pois nÃ£o aponta para nada
//}

//bool Fila::enfilheirar(Aluno * novo)
//{
//    if (novo==NULL)
//        return false;
//    novo->setProximo(NULL);
//    if (filaVazia())
//    {
//        inicio=final=novo;
//        return true;
//    }
//    final->setProximo(novo);
//    final = novo;
//    return true;
//}

//Aluno * Fila::desenfilheirar()
//{
//    if (filaVazia())
//        return NULL;
//    Aluno * aux = inicio;
//    inicio = inicio->getProximo();
//    aux->setProximo(NULL);
//    if (inicio==NULL)
//        final = NULL;
//    return aux;

//}

//Fila::~Fila()
//{
//    Aluno * aux = NULL;
//    while (!filaVazia()) {
//        aux = desenfilheirar();
//        delete aux;
//    }
//}
