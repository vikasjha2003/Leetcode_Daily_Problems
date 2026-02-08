class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        unordered_set<int> st;
        while(r<nums.size() && r <= k) {
            if(st.find(nums[r]) != st.end()) return true;
            st.insert(nums[r]);
            r++;
        }
        while(r < nums.size()) {
            st.erase(nums[l]);
            l++;
            if(st.find(nums[r]) != st.end()) return true;
            st.insert(nums[r]);
            r++;
        }
        return false;
    }
};