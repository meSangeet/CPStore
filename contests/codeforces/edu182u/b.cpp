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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> used(n + 1);
    
    int zeros = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) zeros++;
        else used[a[i]] = true;
    }
    
    vector<int> zi;
    vector<int> available;
    
    for(int i = 0; i <= n; i++) {
        if(a[i] == 0 and i != n) zi.push_back(i);
        if(i >= 1) if(!used[i]) available.push_back(i);
    }
    
    if(zeros == 1) {
        int zero_pos = zi[0];
        int missing = available[0];
        
        bool would_sort = true;
        for(int i = 0; i < n; i++) {
            if(i == zero_pos) {
                if(missing != i + 1) would_sort = false;
            } else if(a[i] != i + 1) {
                would_sort = false;
            }
        }
        
        if(would_sort) {
            cout <<0<<endl;;
            return;
        }
    }
    
    int left = n, right = -1;
    
    for(int i = 0; i < n; i++) {
        if(a[i] != 0 && a[i] != i + 1) {
            left = min(left, i);
            right = max(right, i);
        }
    }
    
    for(int zero_pos : zi) {
        bool can_be_sorted = true;
        for(int val : available) {
            if(val != zero_pos + 1) {
                can_be_sorted = false;
                break;
            }
        }
        
        if(!can_be_sorted) {
            left = min(left, zero_pos);
            right = max(right, zero_pos);
        }
    }
    
    if(right == -1){
        cout<<0<<endl;
        return;
    }
    
    cout << right - left + 1 <<endl;
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

