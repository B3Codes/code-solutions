class Solution {
public:
    int maxDepth(string s) {
        int maxLen = 0;
        int tempLen = 0;

        for(auto c: s){
            if(c == '('){
                tempLen++;
            } else if(c == ')'){
                maxLen = max (maxLen, tempLen);
                tempLen--;
            }
        }

        return maxLen;
    }
};