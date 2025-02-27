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

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArray(arr, n) { cerr << #arr << " = ["; for (int i = 0; i < n; i++) cerr << arr[i] << (i == n-1 ? "" : ", "); cerr << "]" << endl; }
#define debugVector(v) { cerr << #v << " = ["; for (auto &i : v) cerr << i << ", "; cerr << "]" << endl; }
#define debugSet(s) { cerr << #s << " = {"; for (auto &i : s) cerr << i << ", "; cerr << "}" << endl; }
#define debugMap(m) { cerr << #m << " = {"; for (auto &[key, value] : m) cerr << "{" << key << ": " << value << "}, "; cerr << "}" << endl; }
#define debugPair(p) cerr << #p << " = {" << p.first << ", " << p.second << "}" << endl;
#define debugMatrix(mat) { cerr << #mat << " = [\n"; for (auto &row : mat) { cerr << "  ["; for (auto &el : row) cerr << el << ", "; cerr << "]\n"; } cerr << "]" << endl; }

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

// Solve Function
void solve() {
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    vector<int> ans(n+1);
    vector<int> st(2*n+10, 0);
    for(int i = 1; i<=n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    queue<int> q;

    ans[1] = 1;
    vector<bool> vis(n+1, false);
    vis[1] = true;
    bool flag = true;
    int no = 5;
    for(int nei : tree[1]){
        vis[nei] = true;
        if(flag){
            st[2] = 1;
            flag = false;
            ans[nei] = 2;
            q.push(nei);
            continue;
        }
        if(no > 2*n){
            cout<<-1<<endl;
            return;
        }
        ans[nei] = no;
        st[no] = 1;
        no += 2;
        q.push(nei);
    }
    

    while(!q.empty()){
        int node = q.front();
        debug(node)
        // cout<<"inside node - "<<node<<endl;
        vis[node] = true;
        q.pop();
        no = ans[node];
        int pos = no+1;
        bool flag = false;
        for(int child : tree[node]){
            // cout<<"for child - "<<child<<endl;
            if(!vis[child]){
                if(!flag){
                    flag = true;
                    vis[child] = true;
                    q.push(child);
                    if(!st[pos]){
                        st[pos] = 1;
                        if(pos > 2*n){
                            cout<<-1<<endl;
                            return;
                        }
                        ans[child] = pos;
                        pos = no + 4;
                        continue;
                    }

                    pos = no + 4;
                    while(st[pos]) pos += 2;
                    if(pos > 2*n){
                        cout<<-1<<endl;
                        return;
                    }
                    st[pos] = 1;
                    ans[child] = pos;;
                    continue;
                }
                q.push(child);
                vis[child] = true;
                while(st[pos]){
                    // debug(pos)
                    pos += 2;
                }
                // cout<<pos<<" "<<endl;
                if(pos > 2*n){
                    cout<<-1<<endl;
                    return;
                }

                ans[child] = pos;
                st[pos] = 1;
                pos += 2;
            }
        }
    }


    for(int i = 1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
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