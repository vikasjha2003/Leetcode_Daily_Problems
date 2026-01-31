class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = n-1; i>= 0; i--) {
            int a = nums[i] - nums[0];
            if(a == 0) break;
            res += a;
        }
        return res;
    }
};