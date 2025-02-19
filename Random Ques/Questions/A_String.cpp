#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    string s;
    cin>>s;
    ll ans = 0;
    for(auto x : s){
        if(x == '1') ans++;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, tot;
    cin >> t;
    tot = t;
    while (t--) {
        // cout<<"testcase - "<<tot-t<<endl;
        solve();
    }

    return 0;
}