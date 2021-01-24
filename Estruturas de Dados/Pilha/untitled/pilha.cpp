
#include "pilha.h"

        Pilha::Pilha()
        {
            topo = 0;
            tam = 0;
            vet = 0;
        }
        bool Pilha::setTamanho(short int n)
        {
            if (n>1)
            {
                tam = n;
                vet = new livro * [tam];
                for (int i=0; i<tam; i++)
                {
                   vet[i]=0;
                }
                return true;
            }
            return false;
        }

        short int Pilha::getTamanho ()const
        {
           return tam;
        }

        bool Pilha::pilhaVazia()const
        {
            if (topo==0)
                return true;
            return false;
        }
        bool Pilha::pilhaCheia()const
        {
            if (topo==tam)
                return true;
            return false;
        }

        bool Pilha::push(livro *obj)
        {
            if (obj==0)
                 return false;
            if (pilhaCheia())
                 return false;
            vet[topo] = obj;
            topo ++;
            return true;
        }
        livro * Pilha:: pop()
        {
            if (pilhaVazia())
                return 0;
            livro * aux = vet[topo-1];
            vet[topo-1]=0;
            topo--;
            return aux;
        }

        Pilha::	~Pilha()
        {
            livro  * aux = 0;
            while (topo>0)
            {
                 aux = pop();
                 delete aux;
                 aux = 0;
             }
             delete[]vet;
             vet=0;
        }
