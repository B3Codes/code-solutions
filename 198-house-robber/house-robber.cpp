class Solution {
public:
    // Base Recursive Solution
    /*
    The base recursive solution calculates the maximum amount of money that can be robbed
    by exploring two possibilities for each house:
      1. Skip the current house and move to the next one.
      2. Rob the current house and move to the house after the next one.
    This approach has an exponential time complexity of O(2^n) due to overlapping subproblems.
    */
    // int robHelper(vector<int>& nums, int n) {
    //     if (n < 0)
    //         return 0; // Base case: no houses left to rob.
        
    //     // Take the maximum of:
    //     // - Skipping the current house (robHelper(nums, n-1))
    //     // - Robbing the current house (robHelper(nums, n-2) + nums[n])
    //     return max(robHelper(nums, n-1), robHelper(nums, n-2) + nums[n]);
    // }

    // int rob(vector<int>& nums) {
    //     // Start with the last house in the array.
    //     return robHelper(nums, nums.size() - 1);
    // }

    // Optimized Solution with Memoization (Top-Down Approach)
    /*
    This approach stores intermediate results in a `dp` array to avoid recalculating
    the same subproblem multiple times, reducing the time complexity to O(n).
    */
    // int robHelper(vector<int>& nums, vector<int>& dp, int n) {
    //     if (n < 0)
    //         return 0; // Base case: no houses left to rob.

    //     if (dp[n] != -1) {
    //         return dp[n]; // If already calculated, return the result from dp.
    //     }
        
    //     // Store the result in dp and return it.
    //     dp[n] = max(robHelper(nums, dp, n-1), robHelper(nums, dp, n-2) + nums[n]);
    //     return dp[n];
    // }

    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size() + 1, -1); // Initialize dp array with -1.
    //     return robHelper(nums, dp, nums.size() - 1);
    // }

    // Bottom-Up Dynamic Programming Approach
    /*
    This approach uses an iterative method to build the solution from the ground up,
    storing results for each house in a `dp` array. The time complexity is O(n),
    and the space complexity is O(n) due to the `dp` array.
    */
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0)
    //         return 0; // No houses to rob.
    //     if (n == 1)
    //         return nums[0]; // Only one house to rob.

    //     vector<int> dp(nums.size() + 1, -1); // Initialize dp array.
    //     dp[0] = nums[0]; // If only the first house is considered.
    //     dp[1] = max(nums[0], nums[1]); // Maximum of robbing the first or second house.

    //     // Fill the dp array iteratively.
    //     for (int i = 2; i < n; i++) {
    //         dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    //     }

    //     return dp[n-1]; // The result is stored in dp[n-1].
    // }

    // Space-Optimized Solution
    /*
    This approach eliminates the need for a `dp` array by maintaining only two variables,
    `prev1` and `prev2`, which represent the maximum amounts robbed for the previous two houses.
    The time complexity is O(n), and the space complexity is reduced to O(1).
    */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0; // No houses to rob.
        if (n == 1)
            return nums[0]; // Only one house to rob.

        int prev2 = 0; // Equivalent to dp[i-2], initially 0 since no houses have been robbed yet.
        int prev1 = 0; // Equivalent to dp[i-1], initially 0 since no houses have been robbed yet.

        // Iterate through each house.
        for (int i = 0; i < n; i++) {
            // Calculate the maximum money robbed up to house i.
            int curr = max(prev1, prev2 + nums[i]);
            // Update prev2 and prev1 for the next iteration.
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1; // The result is stored in prev1.
    }
};
