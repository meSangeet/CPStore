#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n,l,r; cin>>n>>l>>r;
    vector<ll> a(n+1);
    vector<ll> ini, bac;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        if(i <= r) ini.push_back(a[i]);
        if(i >= l) bac.push_back(a[i]);
    }
    
    sort(ini.begin(), ini.end());
    sort(bac.begin(), bac.end());
    ll p = 0, q = 0;
    for(int i = 0; i<=(r-l); i++){
        p += ini[i];
        q += bac[i];
    }
    cout<<min(p,q)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int temp = t;
    while (t--) {
        // cout<<"Testcase - "<<temp-t<<endl;
        solve();
    }
    return 0;
}
