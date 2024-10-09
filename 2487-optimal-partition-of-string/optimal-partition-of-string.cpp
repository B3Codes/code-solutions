class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        int n = s.length();
        string temp = "";
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