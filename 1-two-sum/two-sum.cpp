class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i = 0; i<nums.size(); i++) {
            int a = target - nums[i];
            if(mpp.find(a) == mpp.end()) {
                mpp[nums[i]] = i;
            } else return {mpp[a],i};
        }
        return {0,0};
    }
};