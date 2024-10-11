class Solution {
public:
    int partitionString(string s) {
        // int count = 0;
        // int n = s.length();
        // string temp = "";
        // for(int i = 0;i<n;i++) {
        //     auto found = temp.find(s[i]);

        //     if(found != string::npos){
        //         count ++;
        //         temp = "";
        //     } 
            
        //     temp = temp + s[i];
        // }
        

        // return count + 1;


// Optimization: using set - TC: O(n)

        int count = 0;
        int n = s.size();

        unordered_set<char> seenSet;

        for(int i = 0;i<n;i++) {
            if(seenSet.find(s[i]) != seenSet.end()){
                count++;
                seenSet.clear();
            }

            seenSet.insert(s[i]);
        }

        return count + 1;
    }
};