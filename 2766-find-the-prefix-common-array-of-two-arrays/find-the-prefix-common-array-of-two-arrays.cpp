class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C;
        for(int i = 0;i<A.size();i++){
            int count = 0;
            for(int j = 0;j<i+1;j++){
                int temp = A[j];
                int k = i;
                while(k >= 0){
                    if(B[k] == temp){
                        count++;
                        break;
                    }
                    k--;
                }

                
            }
            C.push_back(count);
        }

        return C;
    }
};