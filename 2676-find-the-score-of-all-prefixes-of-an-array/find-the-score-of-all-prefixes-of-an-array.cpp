class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> score(n);
        vector<long long> conver(n);
        
        long long maxVal = INT_MIN;
        long long scoreVal = 0;
        for(int i = 0;i<n;i++){
            if(maxVal < nums[i])
                maxVal = nums[i];
            // maxVal = max(maxVal, nums[i]);
            conver[i] = nums[i] + maxVal;
            score[i] = scoreVal + conver[i];
            scoreVal = score[i];
        }

        return score;
    }
};