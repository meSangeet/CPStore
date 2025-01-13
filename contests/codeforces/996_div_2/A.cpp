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

void solve() {
    ll n, a, b; cin>>n>>a>>b;
    if(abs(b-a)%2 == 0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    int t = 1; 
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
     
