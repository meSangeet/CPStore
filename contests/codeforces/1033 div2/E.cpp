#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1'000'000'007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    vector<tuple<long long, long long, long long>> q(t);
    int maxA = 0;
    for (auto &e : q) {
        long long a, b, k;
        cin >> a >> b >> k;
        e = {a, b, k};
        maxA = max(maxA, int(a));
    }

    vector<long long> inv(maxA + 2);
    inv[1] = 1;
    for (int i = 2; i <= maxA + 1; ++i)
        inv[i] = (MOD - MOD / i * inv[MOD % i] % MOD) % MOD;

    auto C = [&](long long n, int r) -> long long {
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            long long num = (n - r + i) % MOD;
            res = res * num % MOD;
            res = res * inv[i] % MOD;
        }
        return res;
    };

    for (auto [a, b, k] : q) {
        long long n = (a - 1) * k + 1;
        long long comb = C(n, int(a));
        long long m = ((b - 1) % MOD) * (k % MOD) % MOD;
        m = (m * comb + 1) % MOD;
        cout << n % MOD << ' ' << m << '\n';
    }
    return 0;
}


