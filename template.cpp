/*
 *  ♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯
 * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  ┓
 * ┃                                                 ┃
 * ┃   Sangeet's Algorithmic Symphony                ┃
 * ┃   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━                  ┃
 * ┃                                                 ┃
 * ┃   Crafted for Competitive Programming Virtuosos ┃
 * ┃   Optimized for Performance                     ┃
 * ┃   Designed with Precision                       ┃
 * ┃                                                 ┃
 * ┃   [ Efficiency • Elegance • Excellence ]        ┃
 * ┃                                                 ┃
 * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━. ┛
 *  ♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯♭♯
 */


#include <bits/stdc++.h>
using namespace std;

// Orchestrating the performance
#define CONDUCTOR ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define TEMPO_ALLEGRO cout << fixed << setprecision(12)

// notations (type aliases)
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

// Harmonic macros
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define per(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define fore(it, c) for (auto it : (c))

// Rhythmic constants
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-9;

// Melodic utility functions
template<typename T> inline void in(T &x) { cin >> x; }
template<typename T, typename... Args> inline void in(T &x, Args &...args) { cin >> x, in(args...); }
template<typename T> inline void out(const T &x) { cout << x << "\n"; }
template<typename T, typename... Args> inline void out(const T &x, const Args &...args) { cout << x << " ", out(args...); }
template<typename T> inline void vec_in(vector<T> &v) {
    for(int i = 0; i < v.size(); ++i) {
        if(!(cin >> v[i])) {
            cout << "Failed to read element " << i << endl;
            break;
        }
    }
}

template<typename T> inline void vec_out(const vector<T> &v) { fore(x, v) cout << x << " "; cout << "\n"; }

// Virtuoso functions
ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m = MOD) { a %= m; b %= m; return (a + b) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { a %= m; b %= m; return (a - b + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { a %= m; b %= m; return (a * b) % m; }
ll mod_pow(ll x, ll y, ll m = MOD) {
    ll res = 1;
    x %= m;
    while (y > 0) {
        if (y & 1) res = mod_mul(res, x, m);
        y >>= 1;
        x = mod_mul(x, x, m);
    }
    return res;
}
ll mod_inv(ll x, ll m = MOD) { return mod_pow(x, m - 2, m); }

// Prime sieve (Sieve of Eratosthenes)
const int MAX_N = 1e6 + 5;
bitset<MAX_N> is_prime;
vi primes;
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < MAX_N; ++i)
        if (is_prime[i])
            for (int j = i * i; j < MAX_N; j += i)
                is_prime[j] = 0;
    rep(i, 2, MAX_N) if (is_prime[i]) primes.pb(i);
}

// Debugging maestro
#define debug(x) cerr << #x << " = " << x << endl
template<typename T>
void __print(const T &x) { cerr << x; }
template<typename T, typename... Args>
void __print(const T &x, const Args &...args) { cerr << x << ", "; __print(args...); }
#define debugv(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: ["; __print(__VA_ARGS__); cerr << "]" << endl

void maestro() {
    
}

signed main() {
    CONDUCTOR;
    // TEMPO_ALLEGRO;
    
    int performances = 1;
    in(performances); 
    
    while (performances--) {
        maestro();
    }
    
    return 0;
}
