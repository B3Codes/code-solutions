class Solution {
public:
    int subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        dp[0][0] = 1;
        // initialization
        for(int i = 1;i<n+1;i++) {
           dp[i][0] = (nums[i-1] == 0) ? dp[i-1][0]*2 : dp[i-1][0];
        }

        // code for subsetsum
        for(int i = 1;i<n+1;i++) {
            for(int j = 1;j<sum+1;j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            - this is a version of **count of subset with given sum**,
            - we will reduce it to that to solve it
         */

         int n = nums.size();
         int arrSum = 0;

         for(int i = 0;i<n;i++) {
            arrSum += nums[i];
         }

         cout<<"arrSum: "<<arrSum<<endl;

         /*
            - we know s1 + s2 = arrSum  ------- (1)
                && 
              s1 - s2 = target  ------- (2)
            - => using (1) && (2) s1 = (arrSum + target)/2;
            - also partition is only possible if arrSum + target is even else not
            - to find the answer we will see the count of substes whose sum = s1
         */

         if((arrSum + target) % 2 != 0 || target > arrSum || arrSum+target < 0) return 0;

         int s1 = (arrSum + target)/2;

         return subsetSum(nums, s1); // this give us the count of substes with sum = s1


    }
};