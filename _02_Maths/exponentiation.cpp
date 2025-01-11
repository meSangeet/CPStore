#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;

//taking power with modulus
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1; 
    base %= mod;          
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

//modular inverse (division for mod) 

//to divide a number A by X mod M do   A = A*qpow(X) mod M
long long qpow(long long x, long long y = M - 2) {
    long long res = 1;
    while (y) {
        if (y % 2 == 1) {
            res = res * x % M;
        }
        x = x * x % M;
        y /= 2;
    }
    return res;
}