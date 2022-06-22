/*2) Dado a sequência de Fibonacci, onde se inicia por 0 e 1 e o próximo valor sempre será a soma dos 2 valores anteriores (exemplo: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...), escreva um programa na linguagem que desejar onde, informado um número, ele calcule a sequência de Fibonacci e retorne uma mensagem avisando se o número informado pertence ou não a sequência.
*/

#include "stdio.h"
int main(void) {
    long n, fibo = 1, soma = 1, eFibo = 0;
    printf("Informe um número: \n");
    scanf("%ld", &n);
    while(fibo <= n){
      if(fibo == n){
        eFibo = 1;
        break;
      }
      fibo = fibo + soma;
      soma = fibo - soma;
    }
    if(eFibo || n == 0){
      printf("%ld percente à sequência de Fibonacci.", n);
    }else{
      printf("%ld NÃO percente à sequência de Fibonacci.", n);
    }
  return 0;
}
