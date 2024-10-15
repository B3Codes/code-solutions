class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int count = 0;
        int n= s.size();

        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                if(count > 0)
                    res = res + s[i];
                count++;
            }

            if(s[i] == ')'){
                count--;
                if(count > 0)
                    res = res + s[i];
                
            }
        }

        return res;
    }
};