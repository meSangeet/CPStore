#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    ll n, k; 
    cin >> n >> k;
    vector<ll> a(n), h(n);

    // Input the fruits and heights
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];

    ll maxLength = 0; // To store the maximum valid subarray length
    ll currentSum = 0; // To store the sum of the current valid subarray
    ll left = 0; // Left pointer for the sliding window

    for (ll right = 0; right < n; right++) {
        // Add the current tree's fruits
        currentSum += a[right];

        // Check divisibility condition for the heights
        while (left < right && (h[right - 1] % h[right] != 0 || currentSum > k)) {
            currentSum -= a[left]; // Remove the leftmost tree's fruits
            left++;
        }

        // Update the maximum length if the current subarray is valid
        if (currentSum <= k) {
            maxLength = max(maxLength, right - left + 1);
        }
    }

    cout << maxLength << "\n";
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
