class Solution {
public:
    int DFS (unordered_map<int,pair<int,vector<int>>> &mpp, int node) {
        auto it = mpp[node];
        int sum = 0;
        for(int i : it.second) {
            sum += DFS(mpp,i);
        }
        return it.first + sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> mpp;
        for(auto it : employees) {
            mpp[it->id] = {it->importance,it->subordinates};
        }
        return DFS(mpp,id);
    }
};