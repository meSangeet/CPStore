#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <bitset>
#include <numeric>
#include <functional>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cassert>
#include <tuple>
#include <utility>

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

bool check(vector<pair<ll,ll>>& v,ll target) {
    ll score = 0, t = 0;
    for(auto [f,val] : v) {
        ll s = (t == 0) ? ((val+1)/2):(val/2);
        score +=s*f;
        t = (t+(val%2))%2;
    }
    return score >= target;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    map<ll,ll> mp;
    for(auto x : a) mp[x]++;
    
    vector<pair<ll,ll>> v;
    for(auto [x,f] : mp) v.push_back({f,x});
    sort(v.rbegin(), v.rend());
    
    ll l = 0, r = 1e18;
    ll ans = 0;
    
    while(l <= r) {
        ll mid = l+(r-l)/2;
        if(check(v, mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    
    ll a1=0,a2=0,t=0;
    for(auto [f,val] : v) {
        ll s1 = (t == 0) ? ((val + 1) / 2) : (val / 2);
        a1 += s1 * f;
        a2 += (val - s1) * f;
        t = (t + (val%2)) %2;
    }
    cout<<a1<<" "<<a2<<endl;
}

int main() {
    fastIO();
    
    int t = 1;
    cin >> t; 
    
    while(t--) {
        solve();
    }
    
    return 0;
}