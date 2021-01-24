#include <stdio.h>
#include <stdlib.h>

int main ()
{
 /* Declaração de variáveis*/

 int opcao,linhas,colunas;

 float MatrizA[10][10], MatrizB[10][10], C[10][10],escalar;

 int LeValorValidoLinhas(int x, int y);

 int LeValorValidoColunas(int x,int y);

 void LeMatriz(float x[10][10],int lin,int colun, char matriz);

 void SomaMatriz(float S[10][10],int lin,int colun, float x[10][10],float y[10][10]);

 void ImprimeMatriz(float x[10][10],int lin,int colun, char matriz);

 void Subtracaomatriz(float Subt[10][10],int lin,int colun, float A[10][10],float B[10][10]);

 void InicializaMatriz(float matriz[10][10], int lin,int colun);

 void ProdutoEscalar(float matriz[10][10],float A[10][10],float x ,int lin, int colun);

 void ImprimeEscalar (float x);

printf("**************************** ******************\n");
printf("********* M E N U D E O P C O E S ***********\n");
printf("**************************** ******************\n");
do{
    printf ("\nEscolha uma das opcoes de 1 a 7 ");
    printf ("\nDigite [1] para somar duas matrizes ");
    printf ("\nDigite [2] para subtrair a matriz B da matriz A");
    printf ("\nDigite [3] para multiplicar uma matriz por um escalar ");
    printf ("\nDigite [4] para calcular a transposta de uma matriz ");
    printf ("\nDigite [5] para verificar se uma matriz eh simétrica ");
    printf ("\nDigite [6] para calcular o produto de duas matrizes ");
    printf ("\nDigite [7] para terminar ");
    scanf("%d", &opcao);
 }while (opcao <=1 || opcao >7);
 if (opcao != 7)
 {
 switch (opcao)
 {
 case 1:
        system ("cls");
        linhas  = LeValorValidoLinhas (1, 10); //A função faz o teste de consistência
        colunas = LeValorValidoColunas (1, 5);  //A função faz o teste de consistência
        LeMatriz(MatrizA,linhas,colunas,'A');
        LeMatriz(MatrizB,linhas,colunas,'B');
        SomaMatriz(C, linhas,colunas,MatrizA,MatrizB);
        ImprimeMatriz (MatrizA,linhas,colunas,'A');
        printf ("\n");
        ImprimeMatriz (MatrizB,linhas,colunas,'B');
        printf ("\n");
        ImprimeMatriz (C,linhas,colunas,'C');
        break;
 case 2:
        system ("cls");
        linhas  = LeValorValidoLinhas (1, 10); //A função faz o teste de consistência
        colunas = LeValorValidoColunas (1, 5);  //A função faz o teste de consistência
        LeMatriz(MatrizA,linhas,colunas,'A');
        LeMatriz(MatrizB,linhas,colunas,'B');
        Subtracaomatriz(C,linhas,colunas,MatrizA,MatrizB);
        ImprimeMatriz (MatrizA,linhas,colunas,'A');
        printf ("\n");
        ImprimeMatriz (MatrizB,linhas,colunas,'B');
        printf ("\n");
        ImprimeMatriz (C,linhas,colunas,'C');
        break;
 case 3:
        system ("cls");
        linhas  = LeValorValidoLinhas (1, 10); //A função faz o teste de consistência
        colunas = LeValorValidoColunas (1, 5);  //A função faz o teste de consistência
        LeMatriz(MatrizA,linhas,colunas,'A');
        printf ("\n Informe o número que ira fazer produto com a matriz: ");
        scanf("%f", &escalar);
        InicializaMatriz(C, linhas,colunas);
        ProdutoEscalar(C,MatrizA,escalar ,linhas,colunas);
        ImprimeEscalar (escalar);
         printf ("\n");
        ImprimeMatriz (MatrizA,linhas,colunas,'A');
         printf ("\n");
        ImprimeMatriz (C,linhas,colunas,'C');
        break;


}
 }}

 int LeValorValidoLinhas(int x, int y)
 {
     int matrizlinhas;
        printf("\n Informe o numero de linhas da matriz: ");
        scanf ("%i", &matrizlinhas);
        while (matrizlinhas < x || matrizlinhas > y)
              {
               system ("cls");
               printf("\n Informe o numero de linhas da matriz entre %i e %i: ",x,y);
               scanf ("%i", &matrizlinhas);
              }
    printf("\n");
    system ("cls");
    return (matrizlinhas);
 }
 int LeValorValidoColunas(int x,int y)
 {
     int matrizcolunas;
        printf("\n Informe o numero de colunas da matriz: ");
        scanf ("%i", &matrizcolunas);
        while (matrizcolunas < x || matrizcolunas > y)
              {
               system ("cls");
               printf("\n Informe o numero de linhas da matriz entre %i e %i: ",x,y);
               scanf ("%i", &matrizcolunas);
              }
    printf("\n");
    system ("cls");
    return (matrizcolunas);
 }

void LeMatriz(float x[10][10],int lin,int colun, char matriz)
    {
        int i,j;
         printf("\n Informe os elementos da matriz %c:\n\n", matriz);

         for (i=0;i<lin;i++)
        {
            for(j=0;j<colun;j++)
            {
                printf("%c[%d][%d]: ",matriz,i,j);
                scanf("%f",&x[i][j]);
            }
        }
    system("pause");
    system("cls");
}

void SomaMatriz(float S[10][10],int lin,int colun, float x[10][10],float y[10][10])
{

    int i, j;
       for (i=0; i < lin;i++)
        for (j=0; j < colun; j++)
             S[i][j] = x[i][j] + y[i][j];
}

void ImprimeMatriz(float x[10][10],int lin,int colun, char matriz)
{
    int i,j;

    for (i=0;i<lin;i++)
         for(j=0;j<colun;j++)
             printf("\n Matriz%c[%i][%i]: %2.2f",matriz,i,j,x[i][j]);
}
void Subtracaomatriz(float Subt[10][10],int lin,int colun, float A[10][10],float B[10][10])
{
       int i, j;
       for (i=0; i < lin;i++)
        for (j=0; j < colun; j++)
             Subt[i][j] = A[i][j] - B[i][j];
}

void InicializaMatriz(float matriz[10][10], int lin,int colun)
{
    int i,j;
       for (i=0; i < lin;i++)
        for (j=0; j < colun; j++)
             matriz[i][j] = 1;
}

void ProdutoEscalar(float matriz[10][10],float A[10][10],float x ,int lin, int colun)
{
    int i,j;
       for (i=0; i < lin;i++)
        for (j=0; j < colun; j++)
             matriz[i][j] = A[i][j] * x;
}

void ImprimeEscalar (float x)
{
    printf ("\n O Valor do Escalar foi %.2f.",x);
}
