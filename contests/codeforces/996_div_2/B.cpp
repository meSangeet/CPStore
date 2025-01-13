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
    ll n; cin>>n;
    vector<ll> a(n), b(n);
    ll mg = 0;
    ll ind = -1;
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++){
        cin>>b[i];
        if(b[i] > a[i]){
            if(mg < b[i]-a[i]){
                ind = i;
                mg = b[i]-a[i];
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(i != ind){
            if(a[i]-b[i] < mg){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    // vector<pair<ll,ll>> vec;
    // for(int i = 0; i<n; i++) vec.push_back({a[i], b[i]});
    // sort(vec.begin(), vec.end());
    

 }

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// int main() {
//     fast_io();
//     int t = 1; 
//     cin>>t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }
     


// #define ll long long
// #include<bits/stdc++.h>
// using namespace std;

int main() {
    ll t;
    cin >> t;
    
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        
        for(int i = 0 ; i < n ; i++)
        cin >> a[i];
        
        for(int i = 0 ; i < n;  i++)
            cin >> b[i];
        
        int count = 0;
        int idx = -1;
        
        for(int i = 0 ; i < n ; i++)
        {
            c[i] = a[i] - b[i];
            if(c[i] < 0)
            {
                count++;
                idx= i;
            }
        }
        if(count == 0) cout<<"YES\n";
        else if(count > 1)
        {
            cout << "NO" << endl;
        }else{
            bool flag = true;
            for(int i = 0 ; i < n ; i++)
            {
                if(idx != i)
                {
                    if(abs(c[idx]) > c[i])
                    flag = false;
                }
            }
            if(flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        
    }
    return 0;
}