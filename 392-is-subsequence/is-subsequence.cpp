class Solution {
public:
    bool isSubsequence(string s, string t) {
        // will solve it using LCS
        // if lenght(LCS) == length(s) return true else false
        
        int n = s.size(), m = t.size();
        // intialization
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // main code for LCS
        for(int i = 1;i<n+1;i++) {
            for(int j = 1;j<m+1;j++) {
                //matching
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n][m] == n;
    }
};