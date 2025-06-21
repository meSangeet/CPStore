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
    vector<ll> a(2*n+1);
    set<ll> s;
    set<ll> completed;
    for(int i = 1; i<=2*n-1; i += 2){
        cin>>a[i];
        cin>>a[i+1];
        if(a[i] == a[i+1]){
            if(!completed.count(a[i])){
                //we don't need to change these elements
                completed.insert(a[i]);
                s.insert(a[i]);
                //now we can actually change these elements to -1 so that we don't consider them again
                a[i] = -1;
                a[i+1] = -1;
            }
        }
    }
    ll ans = 0;
    //till now we have fixated the elements which are already at their right place and need not change
    for(int i = 1; i<=2*n-1; i += 2){
        //if the elements are -1 we can move ahead
        if(a[i] == -1){
            continue;
        }

        //now both the elements will not be -1
        //s set will contain the elements which are taken into account in the second iteration
        //it is possible that both the elements are same but are not -1 as they are somewhere else too
        //so now we need to change both
        if(a[i] == a[i+1]){
            ans += 2;
            continue;
        }

        bool firstTaken = s.count(a[i]);
        bool secondTaken = s.count(a[i+1]);

        if(firstTaken and secondTaken){
            //both the elements are taken both will be changed
            ans += 2;
            continue;
        }

        if(firstTaken){
            //second can sit as it is
            ans++;
            s.insert(a[i+1]);
            continue;
        }

        if(secondTaken){
            //first can sit as it is
            ans++;
            s.insert(a[i]);
            continue;
        }

        //if both are not taken and they are different too
        //keep the first as it is
        s.insert(a[i]);
        ans++;
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