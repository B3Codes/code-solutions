class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        // for(int i = 0;i<words.size();i++){
        //     string temp = words[i];
        //     string charTemp = "";
        //     for(int c = 0; c<temp.size();c++){
        //         if(temp[c] == separator){
        //             if(charTemp != "")
        //             res.push_back(charTemp);
        //             charTemp = "";
        //             continue;
        //         }

        //         charTemp.push_back(temp[c]);
        //     }
        //     if(charTemp != "")
        //     res.push_back(charTemp);
        // }

        for(const auto& word : words) {
            string currentSegment;
            for(char ch: word) {
                if(ch == separator) {
                    if(!currentSegment.empty()){
                    res.push_back(currentSegment);
                    currentSegment.clear();
                    }
                } else {
                    currentSegment.push_back(ch);
                }
            }

            if(!currentSegment.empty()){
                res.push_back(currentSegment);
            }
        }

        return res;
    }

    
};