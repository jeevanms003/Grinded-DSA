class Solution {
public:

    bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int,int>> q;   // {node, parent}
        q.push({start, -1});
        visited[start] = true;

        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for(int neighbor : adj[node]) {

                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                else if(neighbor != parent) {
                    return true;  // cycle found
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj) {

        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(bfs(i, adj, visited))
                    return true;
            }
        }

        return false;
    }
};


Time Complexity: O(V + E) because each vertex and edge is visited once.
Space Complexity: O(V) due to the visited array and BFS queue.


class Solution {
public:

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : adj[node]) {

            if(!visited[neighbor]) {
                if(dfs(neighbor, node, adj, visited))
                    return true;
            }
            else if(neighbor != parent) {
                return true;   // cycle detected
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj) {

        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};