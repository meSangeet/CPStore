#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to interact with the system and make queries
int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    // cout.flush();
    int response;
    cin >> response;
    
    return response;
}

void solve(int t) {
    ll n;
    cin >> n; // Read n
    
    ll x[n + 1]; // Using 1-based indexing
    map<ll, ll> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        m[x[i]]++;
    }
    
    // If the number of unique elements in the array is not equal to n
    // then perform the check logic
    if (m.size() != n) {
        // Iterate over numbers starting from 1 up to n
        for (ll no = 1; no <= n; ++no) {
            if (m[no] == 0) { // If no is not in x, it should not have any edge to y
                ll qq = query(no, x[1]); // Query for this missing number with x[1]
                if (qq == 0) {
                    cout << "! A" << endl;
                    return;
                }
                cout << "! B" << endl;
                return;
            }
        }
    }

    // // Query between 1the first and last index of the array
    ll q1 = query(1, n);
    if (q1 < n-1) {
        cout << "! A" << endl;
        return;
    }

    if(q1 > n-1){
        cout<<"! B\n";
        return;
    }

    ll q2 = query(n, 1);

    if(q1 == q2){
        cout<<"! B\n";
    }else{
        cout<<"! A\n";
    }
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        solve(t);
    }

    return 0;
}