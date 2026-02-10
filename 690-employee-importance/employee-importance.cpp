class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,vector<int>>> mpp;
        for(auto it : employees) {
            mpp[it->id] = {it->importance,it->subordinates};
        }
        queue<int> q;
        int res = 0;
        q.push(id);
        while(!q.empty()) {
            auto it = mpp[q.front()];
            q.pop();
            res += it.first;
            for(int i : it.second) {
                q.push(i);
            }
        }
        return res;
    }
};