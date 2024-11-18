class Solution {
public:
    int myAtoi(string s) {
        int n= s.size();
        int res = 0;
        bool negNum = false;

        int i = 0;
        while(s[i] == ' ') {
            i++;
        }

        int firstChar = s[i];

        if(firstChar == '-'){
            negNum = true;
        } else if(firstChar == '+') {
            negNum = false;
        } else if(firstChar - '0' < 0 || firstChar - '0' > 9 ){
            return 0;
        } else if(firstChar - '0' >= 0 && firstChar - '0' < 10) {
            res = firstChar - '0';
        }

       
        for(i=i+1;i<n;i++){
            int digit = s[i] - '0';
            if(digit <  0 || digit > 10){
                break;
            } 
    
            if(negNum) {
                if(res < (INT_MIN + digit) / 10) {
                    res = INT_MIN;
                    break;
                } else {
                    res = res*10 - digit;
                }
                
            } else {
                if(res > (INT_MAX -  digit) / 10) {
                    res = INT_MAX;
                    break;
                } else {
                    res = res*10 + digit;
                }
                
            }
            
        }

        return res;
        
    }
};