class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char,int> freqMap;
        // count the chracter fequency - use hashmap
        for(auto c: s){
            freqMap[c]++;
        }

        int maxFreq = 0;
        // finding the max frequency
        for(auto x: freqMap){
            if(x.second > maxFreq){
                maxFreq = x.second;
            }
        }

        // store characters by freq - using vector of string
        vector<string> freqVec(maxFreq+1, "");

        for(auto x: freqMap){
            freqVec[x.second] = freqVec[x.second] + string(x.second, x.first);
        }

        // construct the result
        string res = "";
        for(int i = maxFreq; i>0;i--){
            res = res + freqVec[i];
        }

        return res;
    }
};