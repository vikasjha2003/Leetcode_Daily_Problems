class Solution {
public:
    bool BFS (vector<vector<int>>& graph, vector<int>& check, int i) {
        queue<int> q;
        q.push(i);
        check[i] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i : graph[node]) {
                if(check[i] == -1) {
                    check[i] = !check[node];
                    q.push(i);
                } 
                else if (check[i] == check[node]) 
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> check(graph.size(), -1);
        for(int i = 0; i<graph.size(); i++) {
            if(check[i] == -1) {
                if(!BFS(graph,check,i)) return false;
            }
        }
        return true;
    }
};