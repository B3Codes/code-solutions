class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        // map<char, int> strMap;

        // for(int i = 0;i< s.size(); i++) {
        //     strMap[s[i]]++;
        // }

        // for(int i = 0;i<t.size();i++){
        //     if(strMap.find(t[i]) == strMap.end()){
        //         return false;
        //     } else {
        //         strMap[t[i]]--;
        //     }
        // }

        // for(auto x: strMap){
        //     if(x.second != 0)
        //         return false;
        // }

        // return true;

        // Using array

        int charArr[26] = {0};

        for(auto x: s){
            charArr[x - 'a']++;
        }

        for(auto x: t){
            charArr[x - 'a']--;
        }

        for(auto x: charArr){
            if(x != 0)
                return false;
        }

        return true;
    }
};