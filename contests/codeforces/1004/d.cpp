#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <iomanip>

using namespace std;

// Aliases
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using pi = pair<ll, ll>;

// Constants
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

// Macros
#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pr(a) cout<<a<<endl;
#define pY pr("YES");
#define pN pr("NO");
#define py pr("Yes");
#define pn pr("No");
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
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

bool func(string s, int len){
    int n = s.length();
    
    //prefix transformation
    map<char, int> mp;
    for(int i = 0; i<len; i++){
        mp[s[i]]++;
    }
    bool ans1 = true;
    int j = n-1;
    int tlen = len;
    while(tlen--){
        if(mp[s[j]] <= 0){
            ans1 = false;
            break;
        }
        mp[s[j]]--;
        j--;
    }

    int l = len;
    while(l < j){
        if(s[l] != s[j]){
            ans1 = false;
            break;
        }
        l++;
        j--;
    }

    if(ans1){ 
        // cout<<"mid - "<<len<<" gives true in func at ans1\n";   
        return true;
    }
    //suffix transformation
    map<char, ll> ms;
    tlen = len;
    j = n-1;
    while(tlen--){
        ms[s[j]]++;
        j--;
    }
    bool ans2 = true;
    for(int ind = 0; ind<len; ind++){
        if(ms[s[ind]] <= 0){
            ans2 = false;
            break;
        }
        ms[s[ind]]--;
    }

    l = len;

    while(l < j){
        if(s[l] != s[j]){
            ans2 = false;
            break;
        }
        l++;
        j--;
    }

    if(ans2){
        // cout<<"mid - "<<len<<" gives true in func at ans2\n";   
        return true;
    }
// cout<<"mid - "<<len<<" gives false in func at ans2\n";   
    return false;

}


// Solve Function
void solve() {
    string s; cin>>s;
    int len = s.length();
    int i = 0, j = len-1;
    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
            continue;
        }

        break;
    }

    if(i >= j){
        //this means that we don't need to replace

        cout<<0<<endl;
        return;
    }

    string str = "";

    for(int ind = i; ind <= j; ind++){
        str.push_back(s[ind]);
    }

    //now we need to binary search on answers using this string

    int slen = str.length();

    // cout<<"slen - "<<slen<<endl;

    int lo = 0;
    int hi = slen;
    int ans = slen;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        //now check for mid

        //first we need to check for the prefix

        //for that make a map of characters after the prefix
        map<char, int> m;
        for(int ind = 0; ind < mid; ind++){
            m[str[ind]]++;
        }

        int remLen = slen - mid;

        if(remLen > mid){
            bool flag = func(str, mid);
            if(flag){
                ans = mid;
                hi = mid-1;
                continue;
            }
            lo = mid+1;
            continue;
        }

        //if the remaining length is less or equal to mid then the solution below should work : CLAIM


        bool ans1 = true;
        bool ans2 = true;
        //iterate over suffix assuming that suffix won't change

        for(int ind = mid; ind < slen; ind++){
            if(m[str[ind]] <= 0){
                ans1 = false;
                break;
            }

            m[str[ind]]--;
        }

        if(ans1){
            ans = mid;
            hi = mid-1;
            // cout<<"mid - "<<mid<<" true at ans1\n";
            continue;
        }

        map<char, int> m2;
        int sel = mid;
        int ind = slen-1;
        while(sel--){
            m2[str[ind]]++;
            ind--;
        }

        while(ind >= 0){
            if(m2[str[ind]] <= 0){
                ans2 = false;
                break;
            }
            m2[str[ind]]--;
            ind--;
        }

        if(ans2){
            ans = mid;
            hi = mid-1;
            // cout<<"mid - "<<mid<<" true at ans2\n";
            continue;
        }
        // cout<<"mid - "<<mid<<" false\n";
        lo = mid+1;
    }

    cout<<ans<<endl;
}

// Main Function
int main() {

    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    // cout<<func("baba", 0);
    return 0;
}