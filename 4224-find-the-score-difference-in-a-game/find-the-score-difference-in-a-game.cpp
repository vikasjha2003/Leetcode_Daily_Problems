class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int res = 0;
        bool flag = true;
        for(int i = 0; i<nums.size(); i++) {
            if (nums[i] % 2 == 1) flag = !flag;
            if (i % 6 == 5) flag = !flag;
            if(flag) res += nums[i];
            else res -= nums[i];
        }
        return res;
    }
};