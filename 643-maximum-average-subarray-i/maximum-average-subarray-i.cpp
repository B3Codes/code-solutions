class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        double maxAvg;
        double temp = 0;
        for(;left<k;left++) {
            temp = temp + nums[left];
        }
        maxAvg = temp/k;
        while(left < nums.size()) {
            temp = temp - nums[left - k] + nums[left];
            
            maxAvg = max(maxAvg, temp/k);
            left++;
        }

        return maxAvg;
    }
};