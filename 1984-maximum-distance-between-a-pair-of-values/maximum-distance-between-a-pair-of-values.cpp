class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int l = 0 , r = 0;
        int ans = 0;

        while (l < n && r < m) {
            if (nums1[l] <= nums2[r]) {
                ans = max(ans, r - l);
                r++;
            } else {
                l++;
                if (l > r) r = l;
            }
        }

        return ans;
    }
};