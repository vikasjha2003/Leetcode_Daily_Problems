class Solution {
public:
    bool DFS(vector<vector<int>> &adj, vector<bool> &visited, 
    vector<bool> &pathvisited, int node, stack<int> &st) {
            pathvisited[node] = visited[node] = true;
            for(int &i : adj[node]) {
                if(pathvisited[i]) return true;
                if(!visited[i]) {
                    if(DFS(adj,visited,pathvisited,i,st)) return true;
                }
            }
            st.push(node);
            pathvisited[node] = false;
            return false;
        }
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adj (n);
        for(auto &i : graph) {
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited (n,false);
        vector<bool> pathvisited (n,false);
        stack<int> st;
        for(int start = 0; start<n; start++) {
            if(!visited[start]) {
                if(DFS(adj,visited,pathvisited,start,st)) return {};
            }
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};