class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        
        visited[node] = true;
        ans.push_back(node);
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        
        vector<bool> visited(V, false);
        vector<int> ans;
        
        dfs(0, adj, visited, ans);
        
        return ans;
    }
};

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        
        visited[node] = true;
        ans.push_back(node);
        
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
        
        vector<bool> visited(V + 1, false);
        vector<int> ans;
        
        dfs(1, adj, visited, ans);   // start from node 1
        
        return ans;
    }
};

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        
        visited[node] = true;
        ans.push_back(node);

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {

        vector<bool> visited(V + 1, false);
        vector<int> ans;

        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, ans);
            }
        }

        return ans;
    }
};

Time Complexity

O(V + E)

V = vertices

E = edges
Each node and edge is visited once.

Space Complexity

O(V)

visited array

recursion stack in worst case