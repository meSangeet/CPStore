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

class DSU {
private:
    vector<ll> grp, diff;
    vector<pair<ll,ll>> ones; 
    ll ref;
    
public:
    DSU(ll n, vector<ll>& pos, string& s) {
        grp.resize(n);
        diff.resize(n, 0);
        for(ll i = 0; i < n; i++) 
            grp[i] = i;
        ref = n-1;
        for(ll i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                ones.push_back({i, pos[i]});
            }
        }
    }
    
    void find(ll x, ll& cur, ll& d) {
        if(grp[x] == x) {
            cur = x;
            d = 0;
            return;
        }
        
        find(grp[x], cur, d);
        diff[x] ^= d;
        d = diff[x];
        grp[x] = cur;
    }
    
    bool unite(ll x, ll y, ll val) {
        ll curL = 0, curR = 0;
        ll diffL = 0, diffR = 0;
        find(x, curL, diffL);
        find(y, curR, diffR);
        
        if(curL == curR) 
            return ((diffL ^ diffR) == val);
            
        grp[curL] = curR;
        diff[curL] = diffL ^ diffR ^ val;
        return true;
    }
    
    bool check(vector<ll>& pos, string& s) {
        for(auto x : ones) {
            int i = x.first;
            if(i > 0 && s[i-1] == '0' && i < s.length()-1 && s[i+1] == '0') {
                if(!unite(pos[i-1], pos[i+1], 1)) {
                    return false;
                }
            }
            else if(i > 0 && s[i-1] == '0') {
                if(!unite(pos[i-1], ref, 0)) {
                    return false;
                }
            }
            else if(i < s.length()-1 && s[i+1] == '0') {
                if(!unite(pos[i+1], ref, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    
    vector<ll> pos(n, -1);
    ll cnt = 0;
    
    for(ll i = 0; i < n; i++) 
        if(s[i] == '0') 
            pos[i] = cnt++;
    
    DSU dsu(cnt + 1, pos, s);
    
    if(dsu.check(pos, s)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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