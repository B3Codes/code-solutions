class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort<vector<int>> sumArr;
        // set<vector<int>> sumArr;
        vector<vector<int>> sumVec;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0)
                    k--;

                else if(sum < 0)
                    j++;

                else{
                    vector<int> numArr = {nums[i], nums[j], nums[k]};
                    sumVec.push_back(numArr);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1])
                        j++;
                    while(j<k && nums[k] == nums[k+1])
                        k--;
                }
            }
        }
        
        
        
        return sumVec;
    }
};