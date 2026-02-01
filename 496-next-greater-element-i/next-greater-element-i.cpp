class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> pos;
        for(int i = 0; i<nums2.size(); i++) {
            pos[nums2[i]] = i;
        }
        for(int &key : nums1) {
            int gr = -1;
            for(int i = pos[key]+1; i<nums2.size(); i++) {
                if(nums2[i] > key) {
                    gr = nums2[i];
                    break;
                }
            }
            key = gr;
        }
        return nums1;
    }
};