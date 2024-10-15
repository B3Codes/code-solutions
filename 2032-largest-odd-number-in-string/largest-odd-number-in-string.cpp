class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() - 1;
        string res = "";
        int end = 0;
        while(n >= 0){
            int digit = num[n] - '0';
            if(digit % 2 != 0){
                break;
            }
            n--;
        }

        return num.substr(0,n+1);;
    }
};