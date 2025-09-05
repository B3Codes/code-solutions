class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);

        for(auto &t: trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }

        for(int i = 1;i<n+1;i++) {
            if(outdegree[i] == 0 && indegree[i] == n-1) return i;
        }

        return -1;
    }
};