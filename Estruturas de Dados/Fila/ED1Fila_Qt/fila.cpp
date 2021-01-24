#include "fila.h"

        Fila::Fila (){
            tam=0;
            final=0;
            vet = new Aluno*[2];
        }
        Fila::~Fila ()
        {
            Aluno * aux = 0;
            while (!filaVazia())
            {
                aux = desenfilheirar();
                delete aux;
            }
        }
        bool Fila::filaVazia() const{
            return (final==0);
        }

        bool Fila::filaCheia()const{
            return (final==tam);
        }

        bool Fila::enfilheirar(Aluno * aux)
        {
            if (filaCheia())
                return false;
            vet[final] = aux;
            final++;
            return true;
        }

        Aluno * Fila::desenfilheirar(){
            if (filaVazia())
                return NULL;
            Aluno * aux;
            aux = vet[0];
            for (int i=0; i<final-1; i++)
            {
                vet[i] = vet[i+1];
            }
            vet[final-1] = NULL;
            final--;
            return aux;
        }

        bool Fila::setTam(int n)
        {
            if (n>3){
                //~Fila();
                vet = new Aluno *[n];
                tam = n;
                return true;
            }
            return true;
        }

        int Fila::getTam()const{
            return tam;
        }
