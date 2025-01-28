class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // vector<int> left_max(n);
        // vector<int> right_max(n);
        
        // int res = 0;
        
        // left_max[0] = height[0];
        // right_max[n-1] = height[n-1];

        // for(int i = 1;i<n;i++){
        //     left_max[i] = max(left_max[i-1], height[i]);
        //     // cout<<":left"<< left_max[i];
        // }

        // for(int i = n-2;i>=0;i--){
        //     right_max[i] = max(right_max[i+1], height[i]);
        // }

        // for(int i = 0;i<n;i++) {
        //     if((min(left_max[i],right_max[i]) - height[i]) > 0)
        //         res += min(left_max[i],right_max[i]) - height[i];
            
        // }


        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int res = 0;

        while(left <= right) {
            if(height[left] < height[right]) {
                if(height[left] > left_max) {
                    left_max = height[left];
                } else {
                    res += left_max - height[left];
                    left++;
                }
                    
            } else {
                if(height[right] > right_max) {
                    right_max = height[right];
                } else {
                    res += right_max - height[right];
                    right--;
                }
            }
        }
        

       return res;
    }
};