class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int> indegree (n,0);
        vector<vector<int>> adj (n);
        for(auto &i : graph) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int &i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        if(res.size() == n) return res;
        return {};
    }
};