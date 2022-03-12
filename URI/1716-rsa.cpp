#include <iostream> 
#include <cmath>
using namespace std;

int GeraPrimos(int n, int Crivo[], int Primos[]);
void GeraCrivo(int n, int Crivo[]);
long int MDCE(long int a, long int b, long int &x, long int &y);
int Exp(int a, int b, int n);
int MultMod(int a, int b, int n);

int crivo[100000000];
int primos[100000000];

int main(){
    long int n, e, c, x, y;

    int b = round(sqrt(1000000000));

    GeraCrivo(b, crivo);
    GeraPrimos(b, crivo, primos);

    cin >> n >> e >> c;

    int i = 1;
    while(n % primos[i] != 0){
        i++;
    }

    int p = primos[i];
    long int q = n / p;
    long int t = (p - 1) * (q - 1);
    int d1 = MDCE(t, e, x, y);
    long int d = t + y;
    long int m = Exp(c, d, n);

    cout << m << endl;

    return 0;
}

void GeraCrivo(int n, int Crivo[]){
    for(int i = 1; i <= n; i++){
        Crivo[i] = i;
    }

    int T = 2;

    for(int i = 1; i <= n/2; i++){
        Crivo[T] = 2;
        T = T + 2;
    }

    for(int i = 3; i <= round(sqrt(n)); i++){
        if(Crivo[i] == i){
            T = i*i;
            int d = i + i;

            while(T <= n){
                if(Crivo[T] == T){
                    Crivo[T] = i;
                }

                T = T + d;
            }
        }
    }
}

int GeraPrimos(int n, int Crivo[], int Primos[]){
    int np = 0;
    for(int i = 2; i <= n; i++){
        if(Crivo[i] == i){
            np++;
            Primos[np] = i;
        }
    }

    return np;
}

// Algoritmo de Euclides estentido, calcula o MDC entre dois números e seus respectivos inversos modulares.
long int MDCE(long int a, long int b, long int &x, long int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    } else {
        long int x2;
        long int y2;
        long int d = MDCE(b, a % b, x2, y2);
        x = y2;
        y = (x2 - (a/b) * y2);
        return d;
    }
        
}

int Exp(int a, int b, int n){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 1){
        return MultMod(Exp(a, b-1, n), a, n);
    } else {
        int x = Exp(a, b/2, n);
        return MultMod(x, x, n);
    }
}

int MultMod(int a, int b, int n){
    long long int la, lb;
    la = a;
    lb = b;
    return (la*lb)%n;
}