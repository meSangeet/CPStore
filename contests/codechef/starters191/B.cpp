#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <iomanip>

using namespace std;

// Aliases
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using pi = pair<ll, ll>;

// Constants
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

// Macros
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pr(a) cout<<a<<endl;
#define pY pr("YES");
#define pN pr("NO");
#define py pr("Yes");
#define pn pr("No");
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
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

// Solve Function
void solve() {
    ll x,y,z; cin>>x>>y>>z;
    //there should be 2 on both of sides of zero
    //that's it 
    //1 - 2, 2 - 3, 3 - 4   noops one 0 can come at the corner actually both 
    if(y == 0 and x <= z+1){
        cout<<"Yes\n";
        return;
    }
    if(z >= x){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}

// Main Function
int main() {

    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}