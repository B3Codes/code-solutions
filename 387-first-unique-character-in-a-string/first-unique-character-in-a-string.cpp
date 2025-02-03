class Solution {
public:
    int firstUniqChar(string s) {
        // vector<int> freqArr(26, 0);

        // for(int i = 0;i<s.size();i++) {
        //     freqArr[s[i] - 'a']++;
        // }

        // for(int i =0;i<s.size();i++) {
        //     if(freqArr[s[i] - 'a'] == 1)
        //         return i;
        // }

        // return -1;


        int n = s.size();

        unordered_map<char,int> freqMap(n);

        for(int i=0;i<n;i++) {
            freqMap[s[i]]++;
        }

        for(int i=0;i<n;i++) {
            if(freqMap[s[i]] == 1) {
                return i;
            }
        }

         return -1;
    }
};