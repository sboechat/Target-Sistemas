/* 5) Escreva um programa que inverta os caracteres de um string.*/

#include <stdio.h>
#include <string.h>


//Percorre a metade do vetor trocando o primeiro valor pelo último, o segundo pelo penúltimo e assim sucessivamente...
void inverteTexto(char *text){
    int tam = strlen(text);
    for (int i = 0; i < tam / 2; i++){
        char aux = text[i];
        text[i] = text[tam - 1 - i];
        text[tam - 1 - i] = aux;
    }
}

int main(){
    char text[200];
    printf("Digite um texto para inverter: ");
    scanf("%[^\n]s", text);
    inverteTexto(text);
    printf("Texto invertido: \n");
    printf("%s", text);
    return 0;
}
