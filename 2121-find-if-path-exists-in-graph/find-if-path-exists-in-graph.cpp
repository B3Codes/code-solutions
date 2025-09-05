class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    /*
        * Build adjacency list from edges.
        * Initialize visited array.
        * BFS/DFS from source.
        * If destination is reached → return true.
        * If traversal ends → return false.
    */

    if(source == destination) return true;


        vector<vector<int>>adj(n);
        

        // Build adjacency list from edges.
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Initialize visited array.
        vector<int> visited(n,-1);
        queue<int> q;

        // BFS/DFS from source.
        visited[source] = 1;
        q.push(source);
       
        while(!q.empty()) {
            int vis = q.front();  
            q.pop();
            visited[vis] = 1;
            for(auto &e: adj[vis]) {
                if(e == destination) return true;
                if(visited[e] == -1) {
                    q.push(e);
                }
            }

            
        }

       

        return false;

    }
};