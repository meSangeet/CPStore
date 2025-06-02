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
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    ll ans = 0;

    for (int i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int seg = 1; seg <= n / 2; seg++) {
        ll s1 = seg;
        ll s2 = n - s1;
        // cout<<s1<<" "<<s2<<endl;
        auto it1 = lower_bound(a.begin(), a.end(), s1);
        auto it2 = lower_bound(a.begin(), a.end(), s2);

        if (it1 == a.end() || it2 == a.end()) continue; // Ensure valid iterators

        ll i1 = it1 - a.begin();
        ll i2 = it2 - a.begin();

        ll e1 = m - i1;
        ll e2 = m - i2;

        ll extra = e1 - e2;
        ll ca = extra * e2;
        ca *= 2;
        ll ca2 = (e2) * (e2 - 1);
        if(s1 != s2) ca2 *= 2;
        ca += ca2;
        // cout<<ca<<endl;
        ans += ca;
    }

    cout << ans << endl;
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