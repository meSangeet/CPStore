#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Check if we can achieve `maxVal` as the maximum value after all operations
bool isPossible(const vector<ll>& A, const vector<ll>& B, ll maxVal) {
    __int128 removal = 0, doubling = 0;
    int N = A.size();

    for (int i = 0; i < N; ++i) {
        __int128 diff = (__int128)maxVal - A[i];
        __int128 usedBoost = min(diff, (__int128)B[i]);

        removal += B[i] - usedBoost;
        doubling += (diff - usedBoost);
    }

    return (2 * removal >= doubling);
}

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N), B(N);
    ll maxA = 0, sumB = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        sumB += B[i];
    }

    ll low = maxA, high = maxA + 2 * sumB;

    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (isPossible(A, B, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
