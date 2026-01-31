class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> freq;
        for(int &i : nums4) {
            for(int &j : nums3) {
                freq[i + j]++;
            }
        }
        int count = 0;
        for(int &i : nums1) {
            for(int &j : nums2) {
                if(freq.find(0-i-j) != freq.end()) {
                    count += freq[0-i-j];
                }
            }
        }
        return count;
    }
};