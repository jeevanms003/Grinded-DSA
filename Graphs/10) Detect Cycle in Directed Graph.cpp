class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited) {

        visited[node] = true;
        pathVisited[node] = true;

        for(int neighbor : adj[node]) {

            // if not visited
            if(!visited[neighbor]) {
                if(dfs(neighbor, adj, visited, pathVisited))
                    return true;
            }

            // if already in current path -> cycle
            else if(pathVisited[neighbor]) {
                return true;
            }
        }

        // remove from current path
        pathVisited[node] = false;

        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& adj) {

        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }

        return false;
    }
};