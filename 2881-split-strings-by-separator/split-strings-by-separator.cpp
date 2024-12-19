class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for(int i = 0;i<words.size();i++){
            string temp = words[i];
            string charTemp = "";
            for(int c = 0; c<temp.size();c++){
                if(temp[c] == separator){
                    if(charTemp != "")
                    res.push_back(charTemp);
                    charTemp = "";
                    continue;
                }

                charTemp.push_back(temp[c]);
            }
            if(charTemp != "")
            res.push_back(charTemp);
        }

        return res;
    }

    
};