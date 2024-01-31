class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> res(m, vector<int>(n));

        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i == m-1 && j == n-1) {
                    res[i][j] = min(0, dungeon[i][j]);
                } else if(i == m-1){
                    res[i][j] = min(0, dungeon[i][j]+res[i][j+1]);
                } else if(j == n-1){
                    res[i][j] = min(0, dungeon[i][j]+res[i+1][j]);
                } else {
                    res[i][j] = min(0, dungeon[i][j] + max(res[i][j+1], res[i+1][j]));
                }
            }
        }

        return abs(res[0][0])+1;
    }
};