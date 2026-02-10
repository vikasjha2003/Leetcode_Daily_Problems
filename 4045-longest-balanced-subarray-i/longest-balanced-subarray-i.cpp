class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen = 0;
        for(int j = 0; j<nums.size() - maxlen; j++) { // doing - maxlen to reduce the range of possible answer
            unordered_set<int> st;
            int count = 0;
            for(int i = j; i<nums.size(); i++) {
                if(st.find(nums[i]) == st.end()) {
                    st.insert(nums[i]);
                    if(nums[i] % 2 == 0) count++;
                    else count--;
                }
                if(count == 0) maxlen = max(maxlen,i-j+1);
            }
        }
        return maxlen;
    }
};