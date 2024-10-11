class Solution {
public:
    int partitionString(string s) {


// Optimization: using set - TC: O(n)

        int count = 0;
        int n = s.size();

        set<char> seenSet;

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