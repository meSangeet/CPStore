#include <bits/stdc++.h>
using namespace std;

int find_mex(set<int> &s) {
    int mex = 1;
    for (int num : s) {
        if (num != mex) return mex;
        mex++;
    }
    return mex;
}

int miniEle(vector<int> arr, int n) {
    int mini = 1e9+10;
    for(int i = 0 ; i < n ; i++)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

void solve(){
        int n;
        cin >> n;
        vector<int> arr(n);
        
        int zero = 0, index = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                if (index == -1) index = i;
                zero++;
            }
        }

        if (zero == 0) {
            cout << n << endl;
            return;
        }

        set<int> s;
        for (int i = index + 1; i < n; i++) {
            if (arr[i] != 0) s.insert(arr[i]);
        }

        int mex = find_mex(s);
        // cout << mex << endl;
        // 6 5 7 4 0 1 2 3 4
        //cout << ans << endl;
            
        //cout << ans << endl;
        //cout << index << endl;
        if (index == 0) {
            cout << n - zero + 1 << endl;
            return;
        }
        int minii = INT_MAX;
        for(int i = index-1; i>=0; i--){ 
            if(arr[i] < mex){
                cout<<n - zero<<endl;
                return;
            }

            s.insert(arr[i]);

            if(arr[i] == mex){
                int newMex = mex;
                while(s.count(newMex)){
                    newMex++;
                }
                mex = newMex;
            }
        }
        cout<<n-zero+1<<endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}
