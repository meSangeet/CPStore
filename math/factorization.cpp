//Largest factor less than equal to the number itself (n > 1)

ll lar(ll n){
    if(n == 1) return 1ll;
    if(n%2 == 0) return n/2;
    for(ll i = 3; i*i <= n; i++){
        if(n%i == 0){
            return n/i;
        }
    }
    return 1;
}
