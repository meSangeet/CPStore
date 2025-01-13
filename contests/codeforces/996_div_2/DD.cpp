#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

bool canReach(ll t, ll n, ll k, ll l, vector<ll>& scarecrows) {
    ll position = 0; // Crow's current position
    for (int i = 0; i < n; ++i) {
        ll minPos = max(0LL, scarecrows[i] - t); // Leftmost scarecrow position at time t
        ll maxPos = min(l, scarecrows[i] + t);   // Rightmost scarecrow position at time t
        if (minPos > position) break;           // No scarecrow within range
        if (position - maxPos < k) {            // Crow needs to teleport
            position = max(maxPos + k, position);
        }
        if (position >= l) return true;         // Crow reached the target
    }
    return position >= l;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k, l;
        cin >> n >> k >> l;
        k *= 2;
        l *= 2;
        vector<ll> scarecrows(n);
        for (int i = 0; i < n; ++i){ cin >> scarecrows[i];
        scarecrows[i] *= 2;}

        // Binary search for minimum time
        ll low = 0, high = l, result = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (canReach(mid, n, k, l, scarecrows)) {
                result = mid; // Store valid time
                high = mid - 1; // Try smaller times
            } else {
                low = mid + 1; // Try larger times
            }
        }
        cout <<result << "\n"; // Output twice the minimum time
    }
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    solve();
    return 0;
}
