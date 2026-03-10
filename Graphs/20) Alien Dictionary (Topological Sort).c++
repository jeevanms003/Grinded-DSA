class Solution {
public:
    string alienOrder(vector<string>& words) {

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // initialize nodes
        for(string word : words){
            for(char c : word){
                indegree[c] = 0;
            }
        }

        // build graph
        for(int i = 0; i < words.size()-1; i++){

            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.size(), w2.size());

            for(int j = 0; j < len; j++){

                if(w1[j] != w2[j]){

                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;

                    break;
                }
            }
        }

        queue<char> q;

        for(auto &p : indegree){
            if(p.second == 0)
                q.push(p.first);
        }

        string result;

        while(!q.empty()){

            char node = q.front();
            q.pop();

            result += node;

            for(char neigh : adj[node]){

                indegree[neigh]--;

                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if(result.size() != indegree.size())
            return "";

        return result;
    }
};