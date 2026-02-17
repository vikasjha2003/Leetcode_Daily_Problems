class Solution {
public:
    void DFS (vector<vector<int>>& graph, vector<vector<int>> &res, vector<int> &ans, int node) {
        if(node == graph.size() -1) res.push_back(ans);
        for(int i : graph[node]) {
            ans.push_back(i);
            DFS(graph,res,ans,i);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> ans = {0};
        DFS(graph, res, ans, 0);
        return res;
    }
};