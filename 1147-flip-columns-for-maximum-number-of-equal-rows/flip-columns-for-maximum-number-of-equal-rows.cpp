class Solution {
public:
// Using Bit Manipulation and map

    int maxRowsAfterFlip(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        map<vector<int>, int> mp;
        int ans = 0;

        for(int i = 0;i<m;i++){
            vector<int> temp(n);
            for(int j = 0;j<n;j++){
                temp[j] = matrix[i][j] ^ 1;
            }

            mp[temp]++;
            ans = max(ans, mp[temp] + mp[matrix[i]]);
        }

        return ans;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        return maxRowsAfterFlip(matrix);
    }
};