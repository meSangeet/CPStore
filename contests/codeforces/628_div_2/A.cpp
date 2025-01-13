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
    ll n; cin>>n;
    vector<vector<ll>> adj;
    vector<ll> degree(n+1);
    vector<ll> ans(n-1, -1);
    bool flag = false;
    ll node = -1;

    for(int i = 0; i<n-1; i++){
        ll p; cin>>p;
        ll q; cin>>q;
        degree[p]++;
        degree[q]++;
        if(degree[p] == 3 || degree[q] == 3){
            if(!flag){
            flag = true;
            ans[i] = 2;
            if(degree[p] == 3){
                node = p;
            }else{
                node = q;
            }
            }
        }
        adj.push_back({p,q});
    }

    if(flag){
        ll cur = 0;
        for(int i = 0; i<adj.size(); i++){
            if(adj[i][0] == node || adj[i][1] == node){
                ans[i] = cur;
                cur++;
            } 

            if(cur == 2){
                break;
            }
        }

        cur = 3;

        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == -1){
                ans[i] = cur;
                cur++;
            }

            cout<<ans[i]<<endl;
        }

        return;
    }

    for(int i = 0; i<n-1; i++){
        cout<<i<<endl;
    }
}

int main() {
    // fast_io();
    int t = 1; // Number of test cases
    // cin >> t; // Uncomment for multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
     
