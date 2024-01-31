class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return n;

        vector<int> nums(n);
        nums[0] = 1;

        int p1 = 0, p2 = 0, p3 = 0;
        int c1 = 2, c2 = 3, c3 = 5;

        for(int i = 1;i<nums.size();i++){
           int nextUgly = min({c1,c2,c3});
           nums[i] = nextUgly;

           if(nextUgly == c1){
               p1++;
               c1 = nums[p1]*2;
           }

           if(nextUgly == c2){
               p2++;
               c2 = nums[p2]*3;
           }

           if(nextUgly == c3){
               p3++;
               c3 = nums[p3]*5;
           }
        }



        return nums[nums.size()-1];
    }
};