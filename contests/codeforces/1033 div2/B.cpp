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
    ll ans = INT_MAX;
    for(int i = 0; i<n; i++){
        // cout<<"i = "<<i<<endl;
        if(i == 0){
            if(abs(a[i] - a[i+1]) <= 1){
                cout<<0<<endl;
                return;
            }
            ll mm = a[i+1];
            ll mx = a[i+1];
            ll tars = a[i]-1;
            ll tarl = a[i]+1;
            // cout<<tars<<" "<<tarl<<endl;
            ll c = 1;
            for(int j = i+2; j<n; j++){
                mm = min(a[j], mm);
                mx = max(a[j], mx);
                // cout<<mm<<" "<<mx<<" it\n";
                if(tars >= mm and tars <= mx){
                    ans = min(ans, c);
                }

                if(a[i] >= mm and a[i] <= mx){
                    ans = min(ans, c);
                }

                if(tarl >= mm and tarl <= mx){
                    ans = min(ans, c);
                }
                c++;
            }
        }else if(i == n-1){
            if(abs(a[i]-a[i-1]) <= 1){
                cout<<0<<endl;
                return;
            }
            ll mm = a[i-1];
            ll mx = a[i-1];
            ll tars = a[i]-1;
            ll tarl = a[i]+1;
            ll c = 1;
            for(int j = i-2; j>=0; j--){
                mm = min(a[j], mm);
                mx = max(a[j], mx);
                if(tars >= mm and tars <= mx){
                    ans = min(ans, c);
                }

                if(a[i] >= mm and a[i] <= mx){
                    ans = min(ans, c);
                }

                if(tarl >= mm and tarl <= mx){
                    ans = min(ans, c);
                }
                c++;
            }
        }else{
            //check both the sides
            if(abs(a[i]-a[i-1]) <= 1 or abs(a[i] - a[i+1]) <= 1){
                cout<<0<<endl;
                return;
            }

            //left side
            ll mm = a[i-1];
            ll mx = a[i-1];
            ll tars = a[i]-1;
            ll tarl = a[i]+1;
            ll c = 1;
            for(int j = i-2; j>=0; j--){
                mm = min(a[j], mm);
                mx = max(a[j], mx);
                if(tars >= mm and tars <= mx){
                    ans = min(ans, c);
                }

                if(a[i] >= mm and a[i] <= mx){
                    ans = min(ans, c);
                }

                if(tarl >= mm and tarl <= mx){
                    ans = min(ans, c);
                }
                c++;
            }
            mm = a[i+1];
            mx = a[i+1];
            c = 1;
            for(int j = i+2; j<n; j++){
                mm = min(a[j], mm);
                mx = max(a[j], mx);
                if(tars >= mm and tars <= mx){
                    ans = min(ans, c);
                }

                if(a[i] >= mm and a[i] <= mx){
                    ans = min(ans, c);
                }

                if(tarl >= mm and tarl <= mx){
                    ans = min(ans, c);
                }
                c++;
            }
        }
    }
    cout<<(ans == INT_MAX ? -1 : ans)<<endl;
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