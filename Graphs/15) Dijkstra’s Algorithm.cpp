class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {

        vector<int> dist(V, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &it : adj[node]) {

                int neighbor = it.first;
                int weight = it.second;

                if(d + weight < dist[neighbor]) {
                    dist[neighbor] = d + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        return dist;
    }
};

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // relax edges V-1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto &e : edges) {

                int u = e[0];
                int v = e[1];
                int w = e[2];

                if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // detect negative cycle
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                // negative cycle exists
                return {-1};
            }
        }

        return dist;
    }
};


class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist) {

        int V = dist.size();

        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {

                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

Key Differences
Feature	Bellman–Ford	Floyd–Warshall
Shortest path type	Single source	All pairs
Negative weights	Yes	Yes
Negative cycle detection	Yes	Yes
Time complexity	O(VE)	O(V³)