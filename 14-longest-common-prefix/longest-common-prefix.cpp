class Solution {
public:
    string commonPrefix(const string &leftPrefix,  const string &rightPrefix) {
        int i = 0;
        while(i < leftPrefix.size() && i < rightPrefix.size() && leftPrefix[i] == rightPrefix[i]) {
            i++;
        }

        return leftPrefix.substr(0,i);
    }
    string longestCommonPrefixHelper(vector<string>& strs, int start, int end) {
        if(start == end)
            return strs[start];

        int mid = (end + start)/2;

        string leftPrefix = longestCommonPrefixHelper(strs, start, mid);
        string rightPrefix = longestCommonPrefixHelper(strs, mid+1, end);
        
        return commonPrefix(leftPrefix, rightPrefix);



    }


    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

// naive approach (Horizontal scanning)
        // string intialPrefix = strs[0];
        
        // for(int i = 1;i<strs.size();i++) {
        //     while (strs[i].find(intialPrefix) != 0) {
        //         intialPrefix = intialPrefix.substr(0, intialPrefix.size() - 1);
        //         if(intialPrefix.empty())
        //             return "";
        //     }
        // }

        // return intialPrefix;

// vertical scanning
    // string intial = strs[0];

    // for(int i  = 0;i<strs[0].size();i++) {
    //     char ch = strs[0][i];
    //     for(int j = 1;j<strs.size();j++) {
    //         if(i >= strs[j].size() || strs[j][i] != ch) {
    //             return strs[0].substr(0, i);
    //         }
    //     }
    // }

    // return strs[0];

// sorting & compare first & last
    // sort(strs.begin(), strs.end());

    // // if(strs.size() == 1 || strs[0].size() == 1)
    // //     return strs[0];
    // int i = 0;
    // for(;i<strs[0].size();i++) {
    //     if(strs[0][i] != strs[strs.size() - 1][i]) {
    //         return strs[0].substr(0, i);
    //     }
    // }

    // if(i == strs[0].size())
    //     return strs[0];
    // else
    //     return "";


// Divide and Conquer
    return longestCommonPrefixHelper(strs, 0, strs.size() - 1);

    }
};