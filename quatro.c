/* 4 - Dois veículos (um carro e um caminhão) saem respectivamente de cidades opostas pela mesma rodovia. 
O carro de Ribeirão Preto em direção a Franca, a uma velocidade constante de 110 km/h e o caminhão de Franca em direção a 
Ribeirão Preto a uma velocidade constante de 80 km/h. Quando eles se cruzarem na rodovia, qual estará mais próximo a cidade de Ribeirão Preto?
*/

#include <stdio.h>

double mathabs(double num){ //Retira o sinal negativo da distância relativa do caminhão, que usa o ponto 0 (Ribeirão Preto) como referencial.
    if (num < 0)
        num = num * -1;
    return num;
}

int main(){
    double msCarro = (110.0 / 3.6), msCaminhao = (-80.0 / 3.6); //Velocidade em metros por segundo. A velocidade do caminhão está relativa em direção ao ponto inicial (Ribeirão Preto).
    /*  - Sabemos que quando os dois automóveis se encontrarem, a soma das distâncias percorridas será de 100km, convertendo para metros dá 100.000m.
        - Com isso podemos calcular o tempo para o encontro de dois corpos (carro e caminhão).
        - Dividindo a distância percorrida pela velocidade do carro menos a velocidade relativa do caminhão, conseguimos o tempo gasto.
        - Se temos o tempo gasto para o encontro e sabemos a velocidade de ambos, podemos calcular a distância que cada um percorreu separadamente.
    */
    double distCarroPedagio = (msCarro*2*5*60); //Calculando em m/s o percurso do carro enquanto o caminhão parou 10 minutos no pedágio.
    double t = (100000.0 - distCarroPedagio) / (msCarro - msCaminhao); //Calculando o tempo para o encontro (descontando a distância percorrida pelo carro enquanto o caminhão estava nos pedágios).
    double distCarro = (msCarro*t) + distCarroPedagio; //Calculando o tamanho do percurso (velocidade * tempo) que o carro percorreu, somando o que percorreu enquanto o caminhão estava parado.
    double distCaminhao = mathabs(msCaminhao*t); //Calculando a distância percorrida pelo caminhão, chamando a função mathabs para remover o sinal negativo.
    if(distCarro > distCaminhao){ //Se a distância do carro for maior, então:
        printf("O carro percorreu uma distância de %.0lfm (%.2lfkm), mais do que o caminhão que percorreu apenas %.0lfm (%.2lfkm).\n", distCarro, distCarro / 1000.0, distCaminhao, distCaminhao / 1000.0);  //Exibindo a mensagem já calculando a velocidade pelo tempo para o encontro.
    }else{//Se não: 
        printf("O caminhão percorreu uma distância de %.0lfm (%.2lfkm), mais do que o carro que percorreu apenas %.0lfm (%.2lfkm).\n", distCaminhao, distCaminhao / 1000.0, distCarro, distCarro / 1000.0);  //Exibindo a mensagem já calculando a velocidade pelo tempo para o encontro.
    }
    return 0;
}
