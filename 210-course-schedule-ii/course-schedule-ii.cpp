class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<int> indegree (n,0);
        vector<vector<int>> adj (n);
        for(auto &i : graph) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        vector<int> res;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) res.push_back(i);
        }
        
        for(int st = 0 ; st<res.size(); st++) {
            int node = res[st];
            for(int &i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0) res.push_back(i);
            }
        }
        if(res.size() == n) return res;
        return {};
    }
};