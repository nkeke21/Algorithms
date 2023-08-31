#include <bits/stdc++.h>
using namespace std;

const int SENTINEL = 998244353;

int n,k,l,m;

long long int modulo;
long long int arr[200003];
long long int factorial[1000003];
long long int confac[1000003];

void facto(){
    factorial[0] = 1;
    for(int i = 1; i <= n; i++){
        factorial[i] = factorial [i-1] % modulo * i % modulo;
    }
}

void reading(){
     for(int i = 1; i < n ; i++){
        cin >> arr[i];
    }
}

long long  binpow(long long  x, long long  y) {
    long long  result = 1;

    while (y > 0) {
        if (y & 1){
            result =  (result * x) % modulo;
        }
        x = x * x % modulo;
        y >>= 1;
    }
    return result % modulo;
}

void filling(){
    for(int i = 0; i <= n; i++){
        confac[i] = binpow(factorial[i], modulo - 2) % modulo;
    }
}


long long int combinations(int x, int y){
    return (factorial[y] % modulo) * (confac[x] % modulo) % modulo  * (confac[y-x] % modulo) % modulo;
}

int main(){
    modulo = SENTINEL;
    long long int result = 1;

    cin >> n;

    facto();
    reading();
    filling();

    for(int i = n - 2; i >= 1; i--){
        if(arr[i] <= arr[i+1] + 1){
            result *= combinations(arr[i], arr[i+1]+1);
            result %= modulo;
        }
    }

    cout << result << endl;
    return 0;
}
