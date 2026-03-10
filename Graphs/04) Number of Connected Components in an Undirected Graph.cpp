class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        // build adjacency list
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                components++;   // found one component
            }
        }

        return components;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {

                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(int nei : adj[node]) {
                        if(!visited[nei]) {
                            visited[nei] = true;
                            q.push(nei);
                        }
                    }
                }

                components++;
            }
        }

        return components;
    }
};



