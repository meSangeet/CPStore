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

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArray(arr, n) { cerr << #arr << " = ["; for (int i = 0; i < n; i++) cerr << arr[i] << (i == n-1 ? "" : ", "); cerr << "]" << endl; }
#define debugVector(v) { cerr << #v << " = ["; for (auto &i : v) cerr << i << ", "; cerr << "]" << endl; }
#define debugSet(s) { cerr << #s << " = {"; for (auto &i : s) cerr << i << ", "; cerr << "}" << endl; }
#define debugMap(m) { cerr << #m << " = {"; for (auto &[key, value] : m) cerr << "{" << key << ": " << value << "}, "; cerr << "}" << endl; }
#define debugPair(p) cerr << #p << " = {" << p.first << ", " << p.second << "}" << endl;
#define debugMatrix(mat) { cerr << #mat << " = [\n"; for (auto &row : mat) { cerr << "  ["; for (auto &el : row) cerr << el << ", "; cerr << "]\n"; } cerr << "]" << endl; }

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

ll ss(ll n){
    ll an = 0;
    while(n){
        an += n%10;
        n /= 10;
    }
    return an;
}
// Solve Function
void solve() {
    ll x,y; cin>>x>>y;
    if(x+1 == y){
        py;
        return;
    }
    if(y >= x){
        pn;
        return;
    }
    ll temp = x-y;
    // temp++;
    if(temp%9 == 8){
        py;
        return;
    }

    pn;
    return;
    if(x > y and (x-y)%9 == 8){
        py;
    }
    else{
        pn;
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