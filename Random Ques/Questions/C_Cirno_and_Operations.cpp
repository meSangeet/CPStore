#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long solve_case() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    if (n == 1) return a[0];

    long long max_sum = LLONG_MIN;
    set<vector<ll>> visited;

    function<void(vector<ll>)> dfs = [&](vector<ll> curr) {
        if (curr.size() == 1) {
            max_sum = max(max_sum, (long long)curr[0]);
            return;
        }

        if (visited.count(curr)) return;
        visited.insert(curr);

        long long curr_sum = accumulate(curr.begin(), curr.end(), 0LL);
        max_sum = max(max_sum, curr_sum);

        // Reverse
        vector<ll> rev_curr = curr;
        reverse(rev_curr.begin(), rev_curr.end());
        dfs(rev_curr);

        // Difference
        vector<ll> diff_curr;
        for (int i = 1; i < curr.size(); i++) {
            diff_curr.push_back(curr[i] - curr[i-1]);
        }
        dfs(diff_curr);
    };

    dfs(a);
    return max_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cout << solve_case() << '\n';
    }

    return 0;
}