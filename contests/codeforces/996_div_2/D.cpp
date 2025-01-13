#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <cassert>
#include <deque>
#include <bitset>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define ll long long

// Main solver function
void solve() {
    // Implement your solution here
    ll n,k,l; cin>>n>>k>>l;
    k *= 2;
    l *= 2;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        a[i] *= 2;
    }
    ll cp = k;
    ll curTime = a[0];
    for(ll i = 1; i<n; i++){
        if(cp >= l){
            cout<<curTime<<"\n";
            return;
        }
        ll mp = a[i] + curTime;
        ll x = a[i] - curTime;
        x -= cp;
        if(x <= 0){
            if(mp <= cp){
                cp = mp+k;
            }else{
                cp += k;
            }
        }
        else{
            x /= 2;
            cp += x+k;
            curTime += x;
        }
    }

    if(cp >= l){
        cout<<curTime<<endl;
        return;
    }

    ll dist = l - cp;

    curTime += dist;
    cout<<curTime<<endl;
}

int main() {
    int t = 1; // Number of test cases
    cin >> t; // Uncomment for multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
