class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        string intialPrefix = strs[0];
        
        for(int i = 1;i<strs.size();i++) {
            while (strs[i].find(intialPrefix) != 0) {
                intialPrefix = intialPrefix.substr(0, intialPrefix.size() - 1);
                if(intialPrefix.empty())
                    return "";
            }
        }

        return intialPrefix;
    }
};