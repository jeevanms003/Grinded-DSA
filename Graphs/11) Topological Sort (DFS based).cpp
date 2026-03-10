class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        
        visited[node] = 1;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }

        // push after visiting neighbors
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        
        vector<int> visited(V, 0);
        stack<int> st;

        // run DFS for all nodes
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        vector<int> ans;

        // pop stack to get ordering
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        vector<int> indegree(V, 0);

        // calculate indegree
        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;

        // push nodes with indegree 0
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};