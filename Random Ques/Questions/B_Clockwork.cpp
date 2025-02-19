#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    bool flag = true;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        ll mm = i;
        mm*=2;
        ll nn = n-i-1;
        nn *= 2;
        // cout<<mm<<" "<<nn<<endl;
        if(a[i] <= max(mm, nn)) flag = false;
    }

    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
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