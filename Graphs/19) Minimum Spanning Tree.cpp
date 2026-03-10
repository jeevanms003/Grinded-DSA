class Solution {
public:

    int findParent(int node, vector<int>& parent) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if(pu == pv)
            return;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int kruskalMST(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        vector<int> parent(V);
        vector<int> rank(V,0);

        for(int i=0;i<V;i++)
            parent[i]=i;

        int mstWeight = 0;

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int pu = findParent(u,parent);
            int pv = findParent(v,parent);

            if(pu != pv) {
                mstWeight += w;
                unionSet(u,v,parent,rank);
            }
        }

        return mstWeight;
    }
};


class Solution {
public:
    int primMST(int V, vector<vector<pair<int,int>>> &adj) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<bool> inMST(V,false);

        pq.push({0,0}); // {weight,node}

        int mstWeight = 0;

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;

            if(inMST[node])
                continue;

            inMST[node] = true;
            mstWeight += weight;

            for(auto &neighbor : adj[node]) {

                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if(!inMST[nextNode]) {
                    pq.push({edgeWeight, nextNode});
                }
            }
        }

        return mstWeight;
    }
};