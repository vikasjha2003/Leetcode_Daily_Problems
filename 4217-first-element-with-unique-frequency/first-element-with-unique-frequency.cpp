class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        unordered_map<int,int> freq_count;
        for(int i = 0; i<n; i++) {
            freq[nums[i]]++;
        }
        for(const auto &it : freq) {
            freq_count[it.second]++;
        }
        for(int i = 0; i<n; i++) {
            if(freq_count[freq[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};