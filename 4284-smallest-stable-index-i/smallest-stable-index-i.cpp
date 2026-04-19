class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int stable = INT_MAX;
        int maxi = 0;
        int mini = -1;
        for(int i = 0; i<n; i++) {
            if (nums[i] > nums[maxi]) {
                maxi = i;
            }
            if(i > mini) {
                mini = i;
                for(int j = i + 1; j<n; j++) {
                    if (nums[j] < nums[mini]) {
                        mini = j;
                    }
                }
            }
            stable = min(stable,nums[maxi] - nums[mini]);
            if(stable <= k) return i;
        }
        return -1;
    }
};