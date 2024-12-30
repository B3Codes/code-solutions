class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // vector<int> C;
        // for(int i = 0;i<A.size();i++){
        //     int count = 0;
        //     for(int j = 0;j<i+1;j++){
        //         int temp = A[j];
        //         int k = i;
        //         while(k >= 0){
        //             if(B[k] == temp){
        //                 count++;
        //                 break;
        //             }
        //             k--;
        //         }

                
        //     }
        //     C.push_back(count);
        // }

        // return C;

        int n = A.size();
        vector<int> freq(n+1, 0);
        
        
        vector<int> C(n);
        int count = 0;

        for(int i = 0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]] == 2){
                count++;
            }

            freq[B[i]]++;
            if(freq[B[i]] == 2){
                count++;
            }


            C[i] = count;
        }

        return C;
    }
};