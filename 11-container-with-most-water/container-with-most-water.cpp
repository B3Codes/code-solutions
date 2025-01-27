class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxH = 0;
        while(i < j) {
            maxH = max(maxH, min(height[i],height[j]) * (j-i));
            height[i] < height[j] ? i++ : j--;
        }

        return maxH;

    }
};