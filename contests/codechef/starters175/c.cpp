#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    unordered_map<int, vector<int>> index_map;
    
    // Store indices of each value and its transformed value
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        index_map[a[i]].push_back(i);
    }

    int max_freq = 0;
    
    // Iterate over all unique elements
    for (auto& [val, indices] : index_map) {
        int original_count = indices.size();
        
        // If the transformed value exists in the array
        int transformed_count = index_map[val * x].size();
        
        // Maximum achievable frequency by transforming a contiguous subarray
        max_freq = max(max_freq, original_count + transformed_count);
    }

    cout << max_freq << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
