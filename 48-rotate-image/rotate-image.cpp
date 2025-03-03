class Solution {
public:
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
        
    //     /* 
    //         1. Transpose
    //         2. Reverse Each Row
    //     */
    //     for(int i = 0;i<n;i++) {
    //         for(int j = i+1;j<n;j++) {
    //             int temp = matrix[i][j];
    //             matrix[i][j] = matrix[j][i];
    //             matrix[j][i] = temp;
    //         }
    //     }

    //     for(int i = 0;i<n;i++) {
    //         int start = 0, end = n-1;

    //         while(start<end) {
    //             int temp = matrix[i][start];
    //             matrix[i][start] = matrix[i][end];
    //             matrix[i][end] = temp;
    //             start++;
    //             end--;
    //         }
    //     }
    // }

// Brutt force
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     vector<vector<int>> roatated(n, vector<int>(m));
        
    //     for(int i = 0;i<n;i++) {
    //         for(int j = 0;j<m;j++) {
    //             roatated[j][n-i-1] = matrix[i][j];
    //         }
    //     }

    //     for(int i = 0;i<n;i++) {
    //         for(int j = 0;j<m;j++) {
    //             matrix[i][j] = roatated[i][j];
    //         }
    //     }
        
    // }


// Cycle Rotation
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left = 0, right = matrix.size() - 1;
        while(left < right) {
             for(int i = 0;i<right - left; i++) {
                int top = left, bottom = right;

                // save topleft
                int temp = matrix[top][left+i];
                
                // move bottom-left into top-left
                matrix[top][left+i] = matrix[bottom - i][left];

                // move bottom-right into bottom-left
                matrix[bottom-i][left] = matrix[bottom][right - i];

                // move top-right into bottom-right
                matrix[bottom][right-i] = matrix[top+i][right];

                // move top-left into top-right
                matrix[top+i][right] = temp;
             }
             left++;
             right--;
        }
    }
    
};