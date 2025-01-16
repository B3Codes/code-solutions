class Solution {
public:
// Base Recursive Solution
    // int robHelper(vector<int>& nums, int n) {
    //     if(n < 0)
    //         return 0;
        
    //     return max(robHelper(nums, n-1), robHelper(nums, n-2) + nums[n]);
    // }

    // int rob(vector<int>& nums) {
    //     return robHelper(nums, nums.size() - 1);
    // }

// Optimizing with Memoization : top-down approach
int robHelper(vector<int>& nums, vector<int> &dp, int n) {
        if(n < 0)
            return 0;

            if(dp[n] != -1) {
                return dp[n];
            }
        
        return dp[n] = max(robHelper(nums, dp, n-1), robHelper(nums, dp, n-2) + nums[n]);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return robHelper(nums, dp, nums.size() - 1);
    }
};