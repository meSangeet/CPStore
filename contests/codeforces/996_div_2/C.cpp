#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int l = s.length();
    ll total_sum = 0; // Holds the target sum for each row/column
    bool flag = false; // Used to track when the first step is made
    int step = 0;
    int x = 0, y = 0; // Starting at (0, 0)
    if (s[l-1] == 'D') { // Move Down
                flag = true;
                for (int i = 0; i < m; i++) total_sum += grid[n-1][i];
        } else if (s[l-1] == 'R') { 
                // First move; calculate the total sum from the first column
                flag = true;
                for (int i = 0; i < n; i++) total_sum += grid[i][m-1];
                                // cout<<total_sum<<endl;
    }
    // cout<<total_sum<<endl;
    grid[n-1][m-1] = 0 - total_sum;
    flag = false;
    while (step <= l) {
        if (s[step] == 'D') { // Move Down
            if (!flag) {
                // First move; calculate the total sum from the first row
                flag = true;
                                ll current_sum = 0;

                for (int i = 0; i < m; i++) current_sum += grid[0][i];
                grid[0][0] = 0 - current_sum;
                // cout<<total_sum<<endl;
            } else {
                // Update tampered cell based on the difference in row sums
                ll current_sum = 0;
                for (int i = 0; i < m; i++) current_sum += grid[y][i];
                grid[y][x] = 0 - current_sum;
                // cout<<y<<" "<<x<<" "<<total_sum<<endl;
            }
            y++; // Move to the next row
        } else if (s[step] == 'R') { // Move Right
            if (!flag) {
                // First move; calculate the total sum from the first column
                flag = true;
                ll current_sum = 0;
                for (int i = 0; i < n; i++) current_sum += grid[i][0];
                grid[0][0] = 0 - current_sum;
                                // cout<<total_sum<<endl;
            } else {
                // Update tampered cell based on the difference in column sums
                ll current_sum = 0;
                for (int i = 0; i < n; i++) current_sum += grid[i][x];
                grid[y][x] = 0 - current_sum;
                                // cout<<y<<" "<<x<<" "<<total_sum<<endl;

            }
            x++; // Move to the next column
        }
        step++;
        // cout<<step<<endl;
    }

        
    // Output the restored grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // cout<<"rows"<<endl;
    // for(int i = 0; i<n; i++){
    //     ll summ = 0;
    //     for(int j = 0; j<m; j++) summ += grid[i][j];
    //     cout<<summ<<" ";
    // }
    // cout<<endl;
    // cout<<"columns"<<endl;
    // for(int i = 0; i<m; i++){
    //     ll summ = 0;
    //     for(int j = 0; j<n; j++) summ += grid[j][i];
    //     cout<<summ<<" ";
    // }
    // cout<<endl;
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
