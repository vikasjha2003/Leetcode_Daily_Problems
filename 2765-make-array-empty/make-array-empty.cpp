class Solution {
public:
    // don't understand fully 
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<pair<int,int>> pos;
        for(int i = 0; i<nums.size(); i++) {
            pos.push_back({nums[i],i});
        }
        sort(pos.begin(),pos.end());
        int n = nums.size();
        long long op = n;
        for(int i = 1; i<n; i++) {
            if(pos[i].second < pos[i-1].second) {
                op += n - i;
            }
        }
        return op;
    }
};