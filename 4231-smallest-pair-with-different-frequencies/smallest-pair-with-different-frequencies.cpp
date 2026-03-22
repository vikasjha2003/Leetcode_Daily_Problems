class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> freq (101,0);
        int mini = 101;
        for(int i = 0; i<nums.size(); i++) {
            freq[nums[i]]++;
            mini = min(mini,nums[i]);
        }
        for(int i = mini + 1 ; i < 101; i++) {
            if(freq[i] != 0 && freq[i] != freq[mini]) {
                return {mini,i};
            }
        }
        return {-1,-1};
    }
};