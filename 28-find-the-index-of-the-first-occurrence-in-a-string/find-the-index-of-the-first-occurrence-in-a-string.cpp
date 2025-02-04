class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j=0, res=0;

        int n = haystack.size();
        int m = needle.size();
        

        while(i <n && j<m) {
            if(haystack[i] == needle[j]) {
                j++;
                i++;
            } else {
                // cout<<"inner whike"<<endl;
                i = res + 1;
                res = i;
                j = 0;
            }
        }

        
        if(j == m) {
                return res;
            }
            
        return -1;
    }
};