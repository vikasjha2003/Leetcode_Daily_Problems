class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;
        res.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++) {
            long long a = nums[i];
            while(res.size() != 0 && res.back() == a) {
                a += res.back();
                res.pop_back();
            }
            res.push_back(a);
        }
        return res;
    }
};