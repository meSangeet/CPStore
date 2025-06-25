#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll helper(string &num, ll pos, bool tight, ll nz, vector<vector<vector<ll>>> &dp){
    //implement
    if(nz > 3) return 0;
    if(pos == num.size()){
        return 1;
    }
    if(dp[pos][tight][nz] != -1) return dp[pos][tight][nz];

    int limit = (tight) ? num[pos] - '0' : 9;
    ll ans = 0;
    for(int d = 0; d <= limit; d++){
        //now we have selected d for the current position
        // bool newTight = (tight) and (d == limit);
        bool newTight;
        if(tight){
            if(d == limit){
                newTight = true;
            }else{
                newTight = false;
            }
        }else{
            newTight = false;
        }

        ll nnz;
        if(d == 0){
            nnz = nz;
        }else{
            nnz = nz+1;
        }
        ans += helper(num, pos+1, newTight, nnz, dp);
    }

    return dp[pos][tight][nz] = ans;
}

void solve() {
    ll l,r; cin>>l>>r;
    string strR = to_string(r);
    string strL = to_string(l-1);
    vector<vector<vector<ll>>> dp1(strR.length()+3, vector<vector<ll>> (2, vector<ll>(4, -1)));
    vector<vector<vector<ll>>> dp2(strR.length()+3, vector<vector<ll>> (2, vector<ll>(4, -1)));
    ll ansL = helper(strL, 0, 1, 0, dp1);
    ll ansR = helper(strR, 0, 1, 0, dp2);
    cout<<ansR - ansL<<endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
