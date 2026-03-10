class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& adj, int src) {

        vector<int> dist(V, INT_MAX);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int neighbor : adj[node]) {

                if(dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }
};