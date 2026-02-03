class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq (201,0);
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++) {
            if(res.size() == freq[nums[i]]) {
                res.push_back({nums[i]});
            } else {
                res[freq[nums[i]]].push_back(nums[i]);
            }
            freq[nums[i]]++;
        }
        return res;
    }
};