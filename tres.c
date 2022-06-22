/* 3) Descubra a lógica e complete o próximo elemento:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static const char * unidades[]  = { "Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove" };
static const char * dez_vinte[] = { "", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove" };
static const char * dezenas[]   = { "", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa" };
static const char * centenas[]  = { "", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos" };


char * strcatb( char * dst, const char * src ){
    size_t len = strlen(src);
    memmove( dst + len, dst, strlen(dst) + 1 );
    memcpy( dst, src, len );
    return dst;
}


char * numero_extenso( char * nome, int n ){
    int c = n / 100;
    int d = n / 10 - c * 10;
    int u = n - (n / 10) * 10;
    int dv = d * 10 + u;

    strcpy( nome, unidades[ u ] );
    if( n < 10 )
        return nome;
        
    if ( (dv > 10) && (dv < 20) ){
        strcpy( nome, dez_vinte[ dv - 10 ] );
    }else{
        if( u == 0 ){
            strcpy( nome, dezenas[ d ] );
        }else{
            strcatb( nome, " e " );
            strcatb( nome, dezenas[d] );
        }
    }

    if( n < 100 )
        return nome;
        
    if( (d == 0) && ( u == 0 ) ){
        if( c == 1 )
            strcpy( nome, "Cem" );
        else
            strcpy( nome, centenas[c] );
    }else{
        strcatb( nome, " e " );
        strcatb( nome, centenas[c] );
    }
    return nome;
}

int main(void) {
    //printf(" a) 1, 3, 5, 7, '9'\n b) 2, 4, 8, 16, 32, 64, '128' \n c) 0, 1, 4, 9, 16, 25, 36, '49' \n d) 4, 16, 36, 64, '100' \n e) 1, 1, 2, 3, 5, 8, '13' \n f) 2,10, 12, 16, 17, 18, 19, '200' \n\n");
    int aux=2, num = 1;
    
    
    //A
    printf(" a) ");
    for(int i=0;i<4;i++){
        printf("%d, ", num);
        num = num + aux;
    }
    printf("'%d'\n", num);
    
    //B
    num = 2;
    printf(" b) ");
    for(int i=0;i<6;i++){
        printf("%d, ", num);
        num = num * aux;
    }
    printf("'%d'\n", num);
    
    //C
    num = 0;
    aux = 1;
    printf(" c) ");
    for(int i=0;i<7;i++){
        printf("%d, ", num);
        num = num + aux;
        aux = aux + 2;
    }
    printf("'%d'\n", num);
 
    //D
    num = 4;
    aux = 12;
    printf(" d) ");
    for(int i=0;i<4;i++){
        printf("%d, ", num);
        num = num + aux;
        aux = aux + 8;
    }
    printf("'%d'\n", num);
 
    //E
    num = 1;
    aux = 0;
    printf(" e) ");
    for(int i=0;i<6;i++){
        printf("%d, ", num);
        num = num + aux;
        aux = num - aux;
    }
    printf("'%d'\n", num);
    
    //F
    aux = 0;
    num = 2;
    char extenso[100];
    printf(" f) ");
    while(aux < 8){
        numero_extenso( extenso, num );
        if(extenso[0] == 'D'){
            if(aux > 6){
                break;
            }else{
              printf("%d, ", num);
              aux ++;
            }
        }
        num++;
    }
    printf("'%d'\n", num);
  return 0;
}
