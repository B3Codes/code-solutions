class Solution {
public:
    int partitionString(string s) {
        int j = 1, count = 0;
        int n = s.length();
        string temp = "";
        // temp = temp + s[0];
        for(int i = 0;i<n;i++) {
            auto found = temp.find(s[i]);

            if(found != string::npos){
                count ++;
                temp = "";
                
                
            } 
            temp = temp + s[i];
            
        }
        

        return count + 1;
    }
};