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

    // int climbStairs(int n) {
    //     vector<int> dp(n+1, 0);

    //     dp[0] = 1;
    //     dp[1] = 1;

    //     for(int i = 2;i<dp.size();i++){
    //         dp[i] = dp[i-1] + dp[i-2]; 
    //     }

    //     return dp[n];
    // }

// Approach 3: Space Optimization (Improving Space Complexity)
int climbStairs(int n) {
    // Base case: 
    // If there are 0 or 1 steps, there is only 1 way to climb (do nothing or take one step).
    if(n == 0 || n == 1)
        return 1;

    // Initialize two variables to store the number of ways to reach the previous two steps.
    // prev1 will store the number of ways to reach the step (i-1) and prev2 will store the number of ways to reach (i-2).
    int prev1 = 1, prev2 = 1;
    int current = 0;
        for(int i =2;i<n+1;i++){
             // Calculate the number of ways to reach the current step (i):
        // This is the sum of the ways to reach the (i-1)th step and the (i-2)th step.
            current = prev1 + prev2;

        // Update prev2 to be prev1 (previous step) for the next iteration

            prev2 = prev1;

        // Update prev1 to be the current (newly calculated) value for the next iteration
            prev1 = current;
        }
    // After the loop, prev1 will hold the number of ways to reach the nth step
        return prev1;
    }
};
