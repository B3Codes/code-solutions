class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        // for(int i = 0;i<nums.size()-1;i++) {
        //     int x = nums[i];
        //     for(int j = i+1;j<nums.size();j++) {
        //        if((nums[j]) == target -  x) {
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }

        //     }
        // }

        // using hashmap

        map<int, int> numsMap;

        for(int i = 0;i<nums.size();i++){
            int compliment = target - nums[i];
            if(numsMap.find(compliment) != numsMap.end()) {
                res.push_back(numsMap[compliment]);
                res.push_back(i);
                return res;
            } else {
                numsMap[nums[i]] = i;
            }
        }

        return res;
    }
};