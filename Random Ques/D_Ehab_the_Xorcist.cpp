#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long u, v;
    cin >> u >> v;

    // Check if it's impossible
    if (v < u || (u % 2 != v % 2)) {
        cout << -1 << endl;
        return;
    }

    if (u == v) {
        if (u == 0) {
            cout << 0 << endl; // Edge case for u = v = 0
        } else {
            cout << 1 << endl;
            cout << u << endl;
        }
        return;
    }

    // If the difference (v - u) is divisible by 2
    long long x = u;
    long long y = (v - u) / 2;

    if ((x ^ y) == x + y) {
        // Two elements are sufficient
        cout << 2 << endl;
        cout << x + y << " " << y << endl;
    } else {
        // Otherwise, use three elements
        cout << 3 << endl;
        cout << x << " " << y << " " << y << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
