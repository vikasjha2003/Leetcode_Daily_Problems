class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int res = 0;
        for(int i = 0; i<n; i++) {
            int lo = i;
            int hi = m-1;
            while(lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if(nums2[mid] < nums1[i]) hi = mid - 1;
                else lo = mid + 1;
            }
            res = max(res,hi - i);
        }
        return res;
    }
};