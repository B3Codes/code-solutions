class Solution {
public:
// Approach 1: Memoization (Top-Down)

    // // Helper function to calculate the number of ways to reach the nth step using recursion and memoization
    // int dpHelper(vector<int> &dp, int n){

    //     // Base cases: 
    //     // - If we're at the 0th step (ground), there is 1 way to stay there (doing nothing).
    //     // - If we're at the 1st step, there's also only 1 way to reach it (1 step).
    //     if(n == 0 || n == 1)
    //         return 1;
        
    //     // If the value for the current step `n` is already calculated (stored in dp[n]), 
    //     // we don't need to recalculate it, so return the cached value.
    //     if(dp[n] != -1)
    //         return dp[n];
        
    //     // Recursive case: 
    //     // The number of ways to reach the nth step is the sum of the ways to reach the (n-1)th and (n-2)th steps.
    //     // This is because we can reach step `n` by taking:
    //     // - A 1-step jump from step `n-1` or
    //     // - A 2-step jump from step `n-2`
    //      return dp[n] = dpHelper(dp, n-1 )+ dpHelper(dp, n-2);
    // }

    // int climbStairs(int n) {
    //     vector<int> dp(n+1, -1);

    //     return dpHelper(dp, n);
    // }


// Approach 2: Optimize with Tabulation (Bottom-Up)

    int climbStairs(int n) {
        vector<int> dp(n+1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2;i<dp.size();i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }

        return dp[n];
    }
};
