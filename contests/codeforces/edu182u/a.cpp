#include <bits/stdc++.h>
using namespace std;

// Shortcuts for common data types and operations
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()

// Loops
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define ROF(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define R0F(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for(auto& a:x)

// Constants
const int MOD = 1e9+7;
const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);

// Debugging template
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cin.exceptions(cin.failbit);
    // cout << setprecision(10) << fixed;
}

// Utility functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_pow(ll b, ll p, ll m) {
    ll r = 1;
    while(p) {
        if(p&1) r = mod_mul(r, b, m);
        b = mod_mul(b, b, m);
        p >>= 1;
    }
    return r;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<ll> pre(n+1, 0);
    for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];

    for (int l=1; l<=n-2; l++) {
        for (int r=l+1; r<=n-1; r++) {
            ll aa = pre[l] % 3;
            ll bb = (pre[r] - pre[l]) % 3;
            ll rem = (pre[n] - pre[r]) % 3;
            if (aa<0) aa+=3;
            if (bb<0) bb+=3;
            if (rem<0) rem+=3;
            if(aa == bb and aa == rem){
                cout<<l<<" "<<r<<endl;
                return;
            }
            if(aa != bb and aa != rem and bb != rem){
                cout<<l<<" "<<r<<endl;
                return;
            }
        }
    }
    cout<<0<<" "<<0<<endl;
}

int main() {
    fastIO();
    
    int t = 1;
    cin >> t;  // Comment this line if there's only one test case
    
    while(t--) {
        solve();
    }
    
    return 0;
}