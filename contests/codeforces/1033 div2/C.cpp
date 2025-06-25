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
    
    ll n; cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            ll sum_ij = a[i] + a[j];
            ll l = j + 1, r = n - 1, idx = j;
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (a[mid] < sum_ij) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ll target = a[n - 1] - sum_ij;
            l = j + 1, r = idx;
            ll pos = idx + 1;  // if no a[k] > target, pos will remain out of bound

            while (l <= r) {
                ll mid = (l + r) / 2;
                if (a[mid] > target) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (pos <= idx) {
                ans += (idx - pos + 1);
            }
        }
    }
    cout<<ans<<endl;
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