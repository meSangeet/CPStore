#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()

// GCD & LCM
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Modular Arithmetic
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }
ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

// Modular Inverse
ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }

//to divide a number A by X mod M do   A = A*qpow(X) mod M
ll qpow(ll x, ll y, ll m = MOD - 2) {
    ll res = 1;
    while (y) {
        if (y % 2 == 1) res = res * x % m;
        x = x * x % m;
        y /= 2;
    }
    return res;
}

// Input/Output Optimization
template <typename T>
void rv(vector<T> &v) { for (auto &x : v) cin >> x; }

template <typename T>
void pv(const vector<T> &v) { for (const auto &x : v) cout << x << " "; cout << "\n"; }

// While dealing with mod make sure the final answer is not a negative number
// Read the question carefully you are literally reading questions wrong in every contest
// Make sure to read the constraints before solving the questions
// Arrive at the solution first and then start coding
// Solve Function

// Compute C(n, r) % MOD using precomputed modular inverses
ll nCr_mod(ll n, int r, const vector<ll>& inv) {
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * ((n - r + i) % MOD) % MOD;
        res = res * inv[i] % MOD;
    }
    return res;
}

void solve() {
    int n;
        cin >> n;
        vector<pair<int, int>> edges;
        vector<vector<ll>> vec(n+1);
        vector<int> degree(n + 1, 0);
        vector<bool> vis(n+1, false);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

    bool val = false;
    ll ff,fv, sv;
    for(int i = 1; i<=n; i++){
        if(vec[i].size() == 2){
            ll n1 = vec[i][0];
            ll n2 = vec[i][1];
                val = true;
                ff = n1;
                fv = i;
                sv = n2;
                break;
        }
    }
    if(!val){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<ll> oi(n+1, 0);
    vis[ff] = true;
    vis[fv] = true;
    cout<<ff<<" "<<fv<<endl;
    cout<<fv<<" "<<sv<<endl;
    vis[sv] = true;
    oi[ff] = 1;
    oi[fv] = 2;
    oi[sv] = 2;
    queue<ll> q;
    q.push(ff);
    q.push(fv);
    q.push(sv);

    while(!q.empty()){
        ll node = q.front();
        vis[node] = true;
        ll oo = oi[node];
        q.pop();
        for(ll nei : vec[node]){
            if(vis[nei]) continue;
            if(oo == 2){
                cout<<nei<<" "<<node<<endl;
                oi[nei] = 1;
                q.push(nei);
            }else{
                cout<<node<<" "<<nei<<endl;
                oi[nei] = 2;
                q.push(nei);
            }
        }
    }

}
// Main Function
int main() {
    #ifndef ONLINE_JUDGE
    freopen("Debug.txt", "w", stderr);
    #endif

    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
