class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum;
        vector<int> sumInd;
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        map<int,int> sumMap;
        int i = 0, j=n-1;
    //     for(int i =0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //         sum = nums[i] + nums[j];
    //         if(sum == target) {
    //             sumInd = {i,j};
    //             break;
    //         }
    //     }
    // }

    // while(i<n) {

    // }

    for(int i =0;i<n;i++){
        int x = target - nums[i];
        // if(sumMap.empty() && sumMap.find(x) == sumMap.end()){
        //     sumMap[x] = i;
        // } else {
        //     sumInd = {sumMap[x], i};
        //     break;
        // }

        if(sumMap.find(x) != sumMap.end()) {
            return {sumMap[x],i};
        }
        sumMap[nums[i]] = i;
    }



    
//     while (i <j){
//     int sum = nums[i] + nums[j];
//     if(sum < target) {
//         i++;
//     } else if(sum > target)
//         j--;
//     else
// {        sumInd = {i,j};
//         break;
//         }

// }
    return {-1,-1};
    }
};