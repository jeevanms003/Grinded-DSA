class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        
        vector<int> bfs;          // stores BFS traversal
        vector<bool> visited(V, false);
        
        queue<int> q;
        
        // start BFS from node 0
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return bfs;
    }
};

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        
        vector<int> bfs;
        vector<bool> visited(V + 1, false);
        
        queue<int> q;
        
        // start BFS from node 1
        q.push(1);
        visited[1] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return bfs;
    }
};


class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        
        vector<int> bfs;
        vector<bool> visited(V + 1, false);
        
        queue<int> q;

        for(int i = 1; i <= V; i++) {
            
            if(!visited[i]) {
                
                q.push(i);
                visited[i] = true;

                while(!q.empty()) {
                    
                    int node = q.front();
                    q.pop();

                    bfs.push_back(node);

                    for(int neighbor : adj[node]) {
                        if(!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return bfs;
    }
};

Time Complexity

O(V + E)

V = number of vertices

E = number of edges

Because each vertex and edge is processed once.

Space Complexity

O(V)

visited array

queue