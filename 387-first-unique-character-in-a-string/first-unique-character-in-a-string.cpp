class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freqArr(26, 0);

        for(int i = 0;i<s.size();i++) {
            freqArr[s[i] - 'a']++;
        }

        for(int i =0;i<s.size();i++) {
            if(freqArr[s[i] - 'a'] == 1)
                return i;
        }

        return -1;

         
    }
};