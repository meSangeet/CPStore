class Solution {
public:
    int longestValidParentheses(string s) {
        //let's say 
        int n = s.length();
        int ans = 0;
        vector<int> dp(n, 0);
        stack<int> st;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty()){
                    continue;
                }

                int ind = st.top();
                st.pop();

                int curLen = i - ind + 1;

                if(ind-1 >= 0){
                    curLen += dp[ind-1];
                }

                dp[i] = curLen;
            }

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};