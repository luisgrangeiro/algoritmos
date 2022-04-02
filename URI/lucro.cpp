/* Resolve o problema de calcular o lucro máximo obtido de uma sequência de elementos descontando um custo.
  Entrada:
  Recebe um valor N que indica a quantidade de elementos do vetor.
  Um inteiro que representa o custo de cada elemento do vetor.
  Uma sequencia até N que representa o lucro de cada elemento do vetor.
  
  Usa o algoritmo de Subsequencia consecutiva de Soma Máxima.
*/

#include <iostream> 
using namespace std;

void SCSM(int n, int& sm, int& im, int& fm, int x[]);

int lista[60];

int main(){

    int n, custo, sm, im, fm;

    while(cin >> n){
        scanf("%d", &custo);

        for(int i = 1; i <= n; i++){
            scanf("%d", &lista[i]);
            lista[i] -= custo;
        }

        SCSM(n, sm, im, fm, lista);

        printf("%d", sm);
        printf("\n");
    }

    return 0;
}

void SCSM(int n, int& sm, int& im, int& fm, int x[]){
    sm = 0;
    im = 0;
    fm = 0;

    int ss = 0;
    int is = 0;
    int fs = 0;

    for(int i = 1; i <= n; i++ ){
        if(ss + x[i] >= 0){
            ss = ss + x[i];
            fs = i;

            if(is == 0){
                is = i;
            }

            if(ss > sm){
                sm = ss;
                im = is;
                fm = fs;
            }
        } else {
            ss = 0;
            is = 0;
            fs = 0;
        }
    }
}
