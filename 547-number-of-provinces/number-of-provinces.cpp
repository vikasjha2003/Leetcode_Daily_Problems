class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj (n);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited (n);
        int res = 0;
        for(int start = 0; start < n; start++) {
            if(!visited[start]) {
                res++;
                queue<int> qu;
                qu.push(start);
                visited[start] = true;
                while(!qu.empty()) {
                    int node = qu.front();
                    qu.pop();
                    for(int next : adj[node]) {
                        if(!visited[next]) {
                            qu.push(next);
                            visited[next] = true;
                        }
                    }
                }
            }
        }
        return res; 
    }
};