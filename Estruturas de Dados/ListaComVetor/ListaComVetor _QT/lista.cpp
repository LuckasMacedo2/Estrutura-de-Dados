#include"lista.h"


Lista::Lista (){
    final = 0;
    vetor = 0;
    tam = 0;
}

void Lista::setTam (int aux){
    this->tam = aux;
    vetor = new Aluno * [tam];
}

bool Lista::listaVazia()const{
    return (final==0);
}
bool Lista::listaCheia()const{
    return (final==tam);
}

Aluno * Lista::retirarAluno (int indice){
        Aluno * aux;
        for (int j = 0; j<final; j++)
        {
           if (indice==j)
           {
               aux = vetor[j];
               for (int i =j; i<final; i++)
               {
                   vetor[i]=vetor[i+1];
               }
               j = final;
           }
        }
        delete vetor[final-1];
        final--;
        return aux;
}

int Lista::buscar (string busca){
    string comp;
    int aux = -1;
    for (int i=0;i<final; i++){
        comp = vetor[i]->getNome();
        if (comp==busca)
        {
            aux = i;
            i = final +1;
        }
    }
    return aux;
}
Lista::~Lista(){
    Aluno * aux =0;
    int i = final;
    while (!listaVazia()){
        aux = retirarAluno(i);
        delete aux;
        i--;
    }
}
int Lista::getFinal () const{
    return final;
}

void Lista::exibirLista ()
{
    for (int i = 0;i<getFinal(); i++)
    {;
        cout<<"\nAluno: "<<vetor[i]->getNome();
        cout<<"\nNúmero de Matricula: "<<vetor[i]->getMat();
        cout<<"\nNúmero de Telefone: "<<vetor[i]->getTel();
        cout<<"\n\n\n";
    }
}


bool Lista::inserirOrdenado (Aluno *aux)
{
    if (listaCheia())
    {
        return false;
    }
    if (aux==NULL)
    {
        return false;
    }
    short i, j;

    for (i=0; i<final && aux->getNome()>vetor[i]->getNome(); i++){

    }
    for (j=final; j>i; j--){
        vetor[j] = vetor[j-1];
    }
    vetor [i] = aux;
    final++;
    return true;
}
