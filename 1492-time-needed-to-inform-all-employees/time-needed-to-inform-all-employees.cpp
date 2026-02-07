class Solution {
public:
    void DFS (vector<vector<int>> &adj, int &maxi, int cur, int head,vector<int> &informtime) {
        maxi = max(maxi,cur);
        for(int i : adj[head]) {
            DFS(adj,maxi,cur + informtime[head], i, informtime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj (n);
        for(int i = 0; i<n; i++) {
            if(manager[i] == -1) continue;
            else adj[manager[i]].push_back(i);
        }
        int max_time = 0;
        DFS(adj,max_time,0,headID,informTime);
        return max_time;
    }
};