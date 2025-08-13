#include <iostream>      // For input/output
#include <vector>        // For vector container
#include <algorithm>     // For sorting, max, min, reverse, etc.
#include <cmath>         // For math functions like sqrt, pow
#include <cstring>       // For memset, memcpy
#include <string>        // For string class
#include <map>           // For map container
#include <unordered_map> // For hash map
#include <set>           // For set, multiset
#include <unordered_set> // For unordered_set
#include <queue>         // For queue, priority_queue
#include <stack>         // For stack
#include <deque>         // For deque
#include <bitset>        // For bit manipulation
#include <limits>        // For numeric limits
#include <cassert>       // For assert()
#include <chrono>        // For time measurement
#include <tuple>         // For tuple
#include <utility>       // For pair, make_pair
#include <climits>       // For INT_MAX, INT_MIN

using namespace std;
#define ll long long

/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/
class Solution {
public:
    int numSquares(int n) {
        //n can only go upto 10^4 the max square will go to 10^2
        vector<int> numbers;
        int i = 1;
        while(i*i <= n){
            numbers.push_back(i*i);
            if(i*i == n) return 1;
            i++;
        }
        int sz = numbers.size();
        //now we need to select the numbers from the vector numbers
        //dp[i][j] -> minimum number of ways of getting to target j using the numbers 
        //at the first i indexes

        vector<vector<int>> dp(numbers.size(), vector<int> (n+1, INT_MAX));
        vector<int> mintn(n+1, INT_MAX);
        mintn[0] = 0;
        //targeting 0 will always need 0 numbers
        // for(auto x : numbers) cout<<x<<" ";
        // cout<<endl<<endl;
        for(int i = 0; i <= sz-1; i++){
            dp[i][0] = 0;
        }
        int mm = 0;
        //now for every target, current element can be selected or not
        for(int tar = 1; tar <= n; tar++){
            int mn = INT_MAX;
            for(int i = 0; i <= sz-1; i++){
                int elem = numbers[i];
                //elem can be selected or not
                //case 1 : selected
                //selection is only possible if tar is greater than or equal to elem
                int rem = tar - elem;
                if(tar >= elem and mintn[rem] != INT_MAX){
                    dp[i][tar] = min(dp[i][tar], mintn[rem]+1);
                }

                //case2 : don't select
                // dp[i][tar] = min(dp[i][tar],mintn[tar]);
                // cout<<dp[i][tar]<<" ";
                mn = min(mn, dp[i][tar]);
            }
            // cout<<endl;

            mintn[tar] = mn;
            // cout<<mn<<" ";
        }
        // cout<<endl;

        return mintn[n];
    }
};

int main(){
    int n; cin>>n;
    Solution sol;
    cout<<sol.numSquares(n)<<endl;
    return 0;
}