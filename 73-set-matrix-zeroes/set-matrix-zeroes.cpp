class Solution {
public:
    // Brutt force
    //  void setZeroes(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
        
    //     for(int i=0;i<n;i++) {
    //         for(int j = 0;j<m;j++) {
    //             int k = i, p = j;
    //             if(matrix[k][p] == 0) {
    //                 while(k>=0) {
    //                     if(matrix[k][p] != 0) {
    //                         matrix[k][p] = INT_MIN + 1;
                            
    //                     }

    //                     k--;
    //                 }
    //                 k = i;
    //                 while(k<n) {
    //                     if(matrix[k][p] != 0) {
    //                         matrix[k][p] = INT_MIN + 1;
                            
    //                     }
    //                     k++;

    //                 }

    //                 k = i;
    //                 while(p >= 0) {
    //                     if(matrix[k][p] != 0) {
    //                         matrix[k][p] = INT_MIN + 1;
                            
    //                     }
    //                     p--;
    //                 }

    //                 p = j;
    //                 while(p<m) {
    //                     if(matrix[k][p] != 0) {
    //                         matrix[k][p] = INT_MIN + 1;
                            
    //                     }
    //                     p++;
    //                 }
    //             }
    //         }
    //     }


    //     for(int i = 0;i<n;i++) {
    //         for(int j = 0;j<m;j++) {
    //             if(matrix[i][j] == INT_MIN + 1)
    //                 matrix[i][j] = 0;
    //         }
    //     }

        
    // }

// using extra row and column
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        set<int> zeroRow;
        set<int> zeroCol;

        // vector<int> zeroPosArr(n*m, 0);

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(matrix[i][j] == 0) {
                    zeroRow.insert(i);
                    zeroCol.insert(j);
                }
            }
        }

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                
                if(zeroRow.find(i) != zeroRow.end() || zeroCol.find(j) != zeroCol.end()) {
                    matrix[i][j] = 0;
                }
            }    
        }
    }
};