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
vector<ll> getbin(ll x){
    vector<ll> ans;
    while(x){
        if(x&1){
            ans.push_back(1);
        }else{
            ans.push_back(0);
        }
        x /= 2;
    }
    reverse(all(ans));
    return ans;
}


void solve() {
    ll x,y; cin>>x>>y;
    if(x == y){
        cout<<0<<endl;
        return;
    }

    if(x < y){
        swap(x,y);
    }

    vector<ll> b1 = getbin(x);
    vector<ll> b2 = getbin(y);

    ll s1 = b1.size();
    ll s2 = b2.size();
    // cout<<s1<<" "<<s2<<endl;
    //if both the sizes are same which means last bit is 1 
    if(s1 == s2){
        ll ans = powl(2, s1);
        ans += powl(2, s1+1);
        cout<<ans<<endl;
        return;
    }

    ll l = 0, j = 0;
    //check for common prefix
    for(int i = 0; i<s2; i++){
        if(b2[i] == b1[j]){
            l++;
        }else{
            break;
        }
        j++;
    }

    //l is length of common prefix

    if(l == s2){
        ll rem = s1 - l;
        cout<<powl(2, rem)<<endl;
        return;
    }

    ll r2 = s2 - l;
    ll r1 = s1 - l;

    ll ans = powl(2, r1);
    ans += powl(2, r2);
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