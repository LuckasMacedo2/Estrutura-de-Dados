#ifndef TESTAARVORE_H
#define TESTAARVORE_H
#include "abp.h"

class TestaArvore
{
private:

public:
    TestaArvore();
    void menu();
    static Item * criarItem();
    void imprimirNO(NoAB *);
    void imprimirArvore(ABP *);
    void imprimirItem(Item *);
};

#endif // TESTAARVORE_H
