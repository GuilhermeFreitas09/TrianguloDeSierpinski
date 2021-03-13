#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Variáveis globais
int N, P; char char_preto; char **quadro;

// Função que cria o quadro em branco e faz a alocação dinâmica de memória
void tela_em_branco(void){
  int rows = (int)(pow(2, N)+4); 
  int cols = (int)(pow(2, N+1)+3);
  int i, j;
  quadro = (char**) calloc(rows,sizeof(char*)); // Alocando o espaço certo na memória para a tela em branco
  for(i = 0; i<rows; i++)
  {
    quadro[i] = (char*) calloc(cols,sizeof(char));
  }
  for (i = 0; i < rows; ++i) //Formando o quadro em branco
  {
    for (j = 0; j < cols; ++j)
    {
      quadro[i][j] = ' '; //Aspas duplas cria char const *, aspas simples cria char *
    }
  }
};

// Função que prepara a moldura no quadro
void tela_com_moldura(void){
  int rows = (int)(pow(2, N)+4); 
  int cols = (int)(pow(2, N+1)+3);
  int i, j;
  for (i = 0; i < rows; ++i)
  {
    for (j = 0; j < cols; ++j)
    {
      if (i==0 || i==rows-1) // Se for a primeira ou última linha
      {
        if (j==0 || j==cols-1) // Se for a primeira ou última coluna
        {
          quadro[i][j] = '+';
        }else{
          quadro[i][j] = '-';
        }
      }else{ // Se for as linhas do meio
        if (j==0 || j==cols-1) // Se for a primeira ou a última coluna
        {
          quadro[i][j] = '|';
        }
      }
    }
  }
};

// Função que printa o triangulo base
void triangulo_base(int altura, int largura, char c){
  int i, j, k;
  k = 0;
  for (i = altura-3; i > 1; --i)
  {
    for (j = 2+k; j < largura-2-k; ++j)
    {
      quadro[i][j] = c;
    }
    ++k;
  }
};

// Função que desenha o triangulo branco no quadro a partir de x, y e altura
void triangulo_branco(int x, int y, int altura){
  /*
  x: coordenada x (ponta inferior do triangulo branco)
  y: coordenada y (ponta inferior do triangulo branco)
  altura: altura do triangulo (que dependerá da base)
  */
  int i, j, k;
  k = 1;
  for (i = 0; i <= altura; ++i)
  {
    if (i!=0)
    {
      for (j = 0; j<k; ++j)
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

// Função recursiva que pinta o quadro
void sierpinski(int x, int y, int altura, int p){
  if (p==1)
  {
    triangulo_branco(x, y, altura);
  }else{
    triangulo_branco(x, y, altura);
    altura = altura/2;
    sierpinski(x-(2*altura), y, altura, p-1); // Esquerda
    sierpinski(x+(2*altura), y, altura, p-1); // Direita
    sierpinski(x, y-(2*altura), altura, p-1); // Cima
  }
};

// Função que mostra o resultado final
void resultado(){
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

int main(void) 
{
  /*
    N: altura do triângulo base será 2^(N)
    P: número de fractais
    char_preto: qualquer caractere do teclado
  */
  printf("Escolha N, P e Caractere:\n"); 
  scanf("%i\n%i\n%c", &N, &P, &char_preto); // Lendo as entradas e salvando nas variáveis
  tela_em_branco(); // Cria a tela em branco na memória
  tela_com_moldura();// Desenha a moldura
  triangulo_base((int)(pow(2, N)+4), (int)(pow(2, N+1)+3), char_preto);// desenha o triangulo base no meio da tela
  sierpinski((int)(pow(2, N)+1), (int)(pow(2, N)+2), (int)(pow(2, N-1)), P); // Inicia a funcao recursiva (coordenadas e altura do primeiro triangulo branco)
  resultado(); // Mostra o resultado final na tela
  return 0;
};