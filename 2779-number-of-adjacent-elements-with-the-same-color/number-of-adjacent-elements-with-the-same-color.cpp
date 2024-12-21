class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m,0);
        vector<int> colors(n, 0);

        int count = 0;
        
        for(int i = 0;i<m;i++){
            int index = queries[i][0];
            int color = queries[i][1];
            
            //   handle decrement logic
            if(index < n-1 && colors[index] != 0  && colors[index] == colors[index + 1]) {
                count--;
            }

            if(index > 0 && colors[index] != 0  && colors[index] == colors[index - 1]){
                count--;
            }
            
            // update the color
            colors[index] = color;

            // Handle incremnet logic
            if(index < n-1 && colors[index] == colors[index + 1]) {
                count++;
            }

            if(index > 0 && colors[index] == colors[index - 1]){
                count++;
            }

            res[i] = count;
            
        }
        return res;
    }
};