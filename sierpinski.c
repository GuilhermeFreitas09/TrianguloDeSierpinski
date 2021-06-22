#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sierpinski.h"

char ** tela_em_branco(int N){
  int rows = (int)(pow(2, N)+4); 
  int cols = (int)(pow(2, N+1)+3);
  char **quadro = (char**) calloc(rows,sizeof(char*));
  for(int i = 0; i<rows; i++)
  {
    quadro[i] = (char*) calloc(cols,sizeof(char));
  }
  for (int i = 0; i < rows; ++i) //Formando o quadro em branco
  {
    for (int j = 0; j < cols; ++j)
    {
      quadro[i][j] = ' ';
    }
  }
  return quadro;
};

void tela_com_moldura(int N, char **quadro){
  int rows = (int)(pow(2, N)+4); 
  int cols = (int)(pow(2, N+1)+3);
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (i==0 || i==rows-1) // Se for a primeira ou última linha
      {
        if (j==0 || j==cols-1) // Se for a primeira ou última coluna
        {
          quadro[i][j] = '+';
        }else{
          quadro[i][j] = '-';
        }
      }else{ // Se forem as linhas do meio
        if (j==0 || j==cols-1) // Se for a primeira ou a última coluna
        {
          quadro[i][j] = '|';
        }
      }
    }
  }
};

void triangulo_base(int altura, int largura, char c, char **quadro){
  int k = 0;
  for (int i = altura-3; i > 1; --i)
  {
    for (int j = 2+k; j < largura-2-k; ++j)
    {
      quadro[i][j] = c;
    }
    ++k;
  }
};

void triangulo_branco(int x, int y, int altura, char **quadro){
  int k=1;
  for (int i = 0; i <= altura; ++i)
  {
    if (i!=0)
    {
      for (int j = 0; j<k; ++j)
      {
        quadro[y-i][x+j] = ' ';
        quadro[y-i][x-j] = ' ';
      }
      ++k;
    }else{
      quadro[y-i][x]= ' ';
    }
  }
};

void sierpinski(int x, int y, int altura, int p, char **quadro){
  triangulo_branco(x, y, altura, quadro);
  if (p!=1)
  {
    triangulo_branco(x, y, altura, quadro);
    altura = altura/2;
    sierpinski(x-(2*altura), y, altura, p-1, quadro); // Esquerda
    sierpinski(x+(2*altura), y, altura, p-1, quadro); // Direita
    sierpinski(x, y-(2*altura), altura, p-1, quadro); // Cima
  } 
};

void resultado(int N, char **quadro){
  int rows = (int)(pow(2, N)+4); 
  int cols = (int)(pow(2, N+1)+3);
  int i, j;
  for (i = 0; i < rows; ++i)
  {
    for (j = 0; j < cols; ++j)
    {
      printf("%c", quadro[i][j]);
    }
    printf("\n");
  }  
};