class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> keyMap, valMap;

        for(int i = 0;i<n;i++) {
            if(keyMap.find(s[i]) == keyMap.end() && valMap.find(t[i]) == valMap.end()){
                keyMap[s[i]] = t[i];
                valMap[t[i]] = s[i];
            } else if(keyMap[s[i]] != t[i] && valMap[t[i]] != s[i]) {
                return false;
            }
            
        }

        return true;
    }
};