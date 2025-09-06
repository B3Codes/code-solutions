class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;

        visited[0] = true;

        for(auto &e: rooms[0]) {
            q.push(e);
        }

        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            if(!visited[ele]){
            visited[ele] = true;

           for(auto &e: rooms[ele]) {
            q.push(e);
        }}
        }

        for(int i = 0;i<visited.size();i++) {
            if(!visited[i]) return false;
        }

        return true;
    }
};