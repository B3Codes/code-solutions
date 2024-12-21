class Solution {
public:
    int longestString(int x, int y, int z) {
        return 2*z + 4*min(x,y) + ((x != y) ? 2 : 0);


    }
};