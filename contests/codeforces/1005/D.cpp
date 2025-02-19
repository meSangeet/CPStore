#include <bits/stdc++.h>
using namespace std; 
const int INF = (1 << 31); 

 
int rec_dp(int pos, int eq1, int eq2, const vector<int>& bitT1, const vector<int>& bitT2, const vector<int>& bitA, 
           vector<vector<vector<int>>> &memo, vector<vector<vector<bool>>> &vis) {
    if(pos < 0) return 0; 
    if(vis[pos][eq1][eq2]) return memo[pos][eq1][eq2];
    int ans = -1;
    for(int b = 0; b < 2; b++){
        if(eq1 == 0 && b < bitT1[pos]) continue;
        int c = b ^ bitA[pos];
        if(eq2 == 0 && c < bitT2[pos]) continue;
 
        int new_eq1 = eq1;
        if(eq1 == 0 && b > bitT1[pos]) new_eq1 = 1;
        int new_eq2 = eq2;
        if(eq2 == 0 && c > bitT2[pos]) new_eq2 = 1;
 
        int sub = rec_dp(pos - 1, new_eq1, new_eq2, bitT1, bitT2, bitA, memo, vis);
        if(sub != -1){
            int candidate = (b << pos) | sub;
            ans = candidate;
            break;
        }
    }
    vis[pos][eq1][eq2] = true;
    memo[pos][eq1][eq2] = ans;
    return ans;
}
 
int combine(int T1, int A, int T2) {
    const int BITS = 31; 
    vector<int> bitT1(BITS), bitT2(BITS), bitA(BITS);
    for (int pos = 0; pos < BITS; pos++){
        int shift = BITS - 1 - pos; 
        bitT1[shift] = (T1 >> shift) & 1;
        bitT2[shift] = (T2 >> shift) & 1;
        bitA[shift] = (A >> shift) & 1;
    }
    vector<vector<vector<int>>> memo(BITS, vector<vector<int>>(2, vector<int>(2, -1)));
    vector<vector<vector<bool>>> vis(BITS, vector<vector<bool>>(2, vector<bool>(2, false)));
 
    int res = rec_dp(BITS - 1, 0, 0, bitT1, bitT2, bitA, memo, vis);
    if(res == -1) res = INF;
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> w(n);
        for (int i = 0; i < n; i++){
            cin >> w[i];
        }
        vector<int> B(n+1, 0);
        for (int k = 1; k <= n; k++){
            B[k] = w[n - k];
        }
        vector<int> dp(n+1, 0), prefix(n+1, 0);
        dp[0] = 0;
        prefix[0] = 0;
        for (int k = 1; k <= n; k++){
            int cur = combine(dp[k-1], prefix[k-1], B[k]);
            dp[k] = cur;
            prefix[k] = prefix[k-1] ^ B[k];
        }
 

        for (int i = 0; i < q; i++){
            int x;
            cin >> x;
            int lo = 0, hi = n, ans = 0;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                if(dp[mid] <= x){
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cout << ans << " ";
        }
        cout<<endl;
    }

    return 0;
}
