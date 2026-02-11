class Solution {
public:
    bool DFS (vector<vector<int>>& graph,vector<bool> &check,vector<bool> &visited,int node) {
        for(int &n : graph[node]) {
            if(!visited[n]) {
                visited[n] = true;
                if(!DFS(graph,check,visited,n)) return false;
            } 
            else if(check[n] == false) return false;
        }
        check[node] = true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited (graph.size(), false);
        vector<bool> check (graph.size(), false);
        for(int i = 0; i <  graph.size(); i++) {
            if(visited[i] == false) {
                visited[i] = true;
                DFS(graph,check,visited,i);
            }
        }
        vector<int> res;
        for(int i = 0; i<graph.size(); i++) {
            if(check[i] == true) res.push_back(i);
        }
        return res;
    }
};