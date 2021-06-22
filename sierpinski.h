/***
Funções utilizadas
***/


// Função faz a alocação dinâmica de memória e pinta o quadro em branco
char ** tela_em_branco(int N);

// Função que prepara a moldura no quadro
void tela_com_moldura(int N, char **quadro);

// Função que printa o triangulo base
void triangulo_base(int altura, int largura, char c, char **quadro);

// Função que desenha o triangulo branco no quadro a partir de x, y e altura
void triangulo_branco(int x, int y, int altura, char **quadro);

// Função recursiva que pinta o quadro
void sierpinski(int x, int y, int altura, int p, char **quadro);

// Função que mostra o resultado final
void resultado(int N, char **quadro);