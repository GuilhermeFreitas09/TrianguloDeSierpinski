#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sierpinski.h"

int main(void) 
{
  int N, P;
  char caractere;
  /*
    N: altura do triângulo base será 2^(N)
    P: número de fractais
    caractere: qualquer caractere do teclado
  */

  printf("Escolha N, P e caractere:\n"); 

  scanf("%i\n%i\n%c", &N, &P, &caractere);

  char **quadro = tela_em_branco(N); 

  tela_com_moldura(N, quadro);

  triangulo_base((int)(pow(2, N)+4), (int)(pow(2, N+1)+3), caractere, quadro);

  sierpinski((int)(pow(2, N)+1), (int)(pow(2, N)+2), (int)(pow(2, N-1)), P, quadro);

  resultado(N, quadro);

  return 0;
};
