class Solution {
public:
    // Function to check if string s is a subsequence of string t.
    // The approach used here is based on computing the Longest Common Subsequence (LCS) between s and t.
    // If the length of the LCS equals the length of s, then s is a subsequence of t.
    bool isSubsequence(string s, string t) {
        // Get the lengths of strings s and t.
        int n = s.size(), m = t.size();
        
        // Create a 2D dynamic programming table (dp) with dimensions (n+1) x (m+1)
        // Each cell dp[i][j] will hold the length of the LCS of s[0...i-1] and t[0...j-1].
        // Initialize all values to 0.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build the dp table from the bottom up.
        // We iterate over each character of s (1-indexed for dp table) and t.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If the characters at the current positions in s and t match,
                // then we add 1 to the result from the previous index positions.
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If the characters do not match, we take the maximum LCS value
                    // from either skipping the current character of s or t.
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        // If the length of the LCS (dp[n][m]) equals the length of s,
        // it means every character in s appears in t in the same order.
        return dp[n][m] == n;
    }
};
