class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq (201,-1);
        int maxi = -1;
        for(int i = 0; i<nums.size(); i++) {
            freq[nums[i]]++;
            maxi = max(maxi,freq[nums[i]]);
        }
        vector<vector<int>> res (maxi+1);
        for(int i = 1; i<201; i++) {
            while(freq[i] >= 0) {
                res[freq[i]].push_back(i);
                freq[i]--;
            }
        }
        return res;
    }
};