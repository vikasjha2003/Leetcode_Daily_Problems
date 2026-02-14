class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph (n);
        vector<int> indegree (n,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<graph[i].size(); j++) {
                revgraph[graph[i][j]].push_back(i);
            }
            indegree[i] = graph[i].size();
        }
        vector<int> res;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                res.push_back(i);
            }
        }
        for(int i = 0; i<res.size() ; i++) {
            int node = res[i];
            for(int j : revgraph[node]) {
                indegree[j]--;
                if(indegree[j] == 0) res.push_back(j);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};