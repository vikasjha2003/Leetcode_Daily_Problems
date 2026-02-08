class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> stk; 
        for(int i = 0; i<nums.size(); i++) {
            long long a = nums[i];
            while(stk.size() != 0 && stk.back() == a) {
                a += stk.back();
                stk.pop_back();
            }
            stk.push_back(a);
        }
        return stk;
    }
};