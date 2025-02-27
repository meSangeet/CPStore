class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        vector<int> dp(n, -1);
        for(int i = n-1; i>=0; i--){
            if(i == n-1){
                dp[i] = 1;
            }

            int finInd = i + nums[i];

            for(int j = i+1; j <= finInd; j++){
                if(j >= n){
                    break;
                }

                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }

        if(dp[0] == 1) return true;
        return false;
    }
};