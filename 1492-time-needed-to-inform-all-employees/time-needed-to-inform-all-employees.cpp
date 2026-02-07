class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj (n);
        for(int i = 0; i<n; i++) {
            if(manager[i] == -1) continue;
            else adj[manager[i]].push_back(i);
        }
        int max_time = 0;
        queue<pair<int,int>> q;
        q.push({headID, 0});
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                int time = node.second + informTime[node.first];
                max_time = max(max_time , time);
                for(int i : adj[node.first]) {
                    q.push({i,time});
                }
            }
        }
        return max_time;
    }
};