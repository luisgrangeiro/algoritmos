/*
  Recebe um valor N <= 5*10^5 que representa a quantidade de elementos de um vetor
  Depois recebe um valor <= 10^9 que representa cada elemento do vetor.
  Usa o Algoritmo de Subsequencia Crescente Máxima para determinar a maior subsequencia desse vetor.
*/

#include <iostream> 
using namespace std;

long long BuscaBinaria(long long T[], long long ini, long long fim, long long x);
long long SCM(long long n, long long S[], long long O[], long long T[]);

#define MAXSIZE 500100

long long T[500100];
long long O[500100];
long long S[500100];

int main(){

    long long n;

    while(cin >> n){

        for(long long i = 1; i <= n; i++){
            scanf("%d", &S[i]);
        }

        long long k = SCM(n, S, O, T);

        cout << k << endl;
    }   

    return 0;
}

long long BuscaBinaria(long long T[], long long ini, long long fim, long long x){
    if(ini > fim)
        return ini;
    else {
        long long m = (ini + fim)/2;
        if(T[m] < x){
            return BuscaBinaria(T, m+1, fim, x);
        } else {
            return BuscaBinaria(T, ini, fim - 1, x);
        }
    }
}

long long SCM(long long n, long long S[], long long O[], long long T[]){
    long long j;
    long long k = 1;
    T[1] = S[1];
    O[1] = 1;

    for(long long i = 2; i <= n; i++){
        if(S[i] > T[k]){
            k += 1;
            T[k] = S[i];
            O[i] = k;
        } else {
            j = BuscaBinaria(T, 1, k, S[i]);
            T[j] = S[i];
            O[i] = j;
        }
    }

    return k;
}
