class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        int answer = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }

        for (auto &entry : indices) {
            const vector<int> &pos = entry.second;
            if (pos.size() < 3) continue;
            for (int l = 0, r = 2; r < pos.size(); l++, r++) {
                int dist = 2 * (pos[r] - pos[l]);
                answer = min(answer, dist);
            }
        }
        
        return (answer == INT_MAX) ? -1 : answer;
    }
};
