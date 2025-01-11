//check prime

#include <iostream>
#include <cmath>
using namespace std;
bool isPrimeOptimized(int n) {
 	if (n <= 1) return false;
 	if (n == 2) return true;
 	if (n % 2 == 0) return false;
 	for (int i = 3; i <= sqrt(n); i += 2) {
     	if (n % i == 0) return false;
 	}
 	return true;
 }

//sieve

vector<int> sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
for (int p = 2; p * p <= n; ++p) {
    	if (isPrime[p]) {
        	for (int i = p * p; i <= n; i += p) {
            	isPrime[i] = false;
        	}
    	}
	}
vector<int> primes;
	for (int i = 2; i <= n; ++i) {
    	if (isPrime[i]) primes.push_back(i);
	}
	return primes;
}

//smallest prime and prime factorization

const int MAX = 100010;
 
vector<ll> smallestPrime(MAX, 0);  // Stores the smallest prime factor for each number
vector<ll> primes;
 
// Function to sieve and fill the smallestPrime array
void sieve() {
	for (int i = 1; i <= MAX; ++i) smallestPrime[i] = i;
 
	for (int p = 2; p * p <= MAX; ++p) {
    	if (smallestPrime[p] == p) {
        	primes.push_back(p);
        	for (int i = p * p; i <= MAX; i += p) {
            	if (smallestPrime[i] == i) {
                	smallestPrime[i] = p;
            	}
        	}
    	}
	}
}
 
// Function to calculate the prime factorization of a number using smallestPrime
map<ll, ll> primeFactorization(ll num) {
	map<ll, ll> factors;
	while (num > 1) {
    	ll prime = smallestPrime[num];
    	factors[prime]++;
    	num /= prime;
	}
	return factors;
}