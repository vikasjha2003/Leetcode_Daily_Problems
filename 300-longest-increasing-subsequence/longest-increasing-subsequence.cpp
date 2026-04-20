class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i<n; i++) {
            bool flag = false;
            for(int j = 0; j<res.size(); j++) {
                if(res[j] >= nums[i]) {
                    res[j] = nums[i];
                    flag = true;
                    break;
                }
            }
            if(!flag) res.push_back(nums[i]);
        }
        return res.size();
    }
};