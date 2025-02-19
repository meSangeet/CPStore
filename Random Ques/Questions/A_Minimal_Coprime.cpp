#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    
    ll l,r; cin>>l>>r;
    if(l == 1 and r == 1){
        cout<<1<<endl;
        return;
    }
    cout<<r-l<<endl;
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
