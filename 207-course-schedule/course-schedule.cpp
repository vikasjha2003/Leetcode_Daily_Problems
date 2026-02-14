class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree (n,0);
        vector<vector<int>> adj (n);
        for(auto &it : prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i<n ; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(int &i : adj[node]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        if(count == n) return true;
        return false;
    }
};