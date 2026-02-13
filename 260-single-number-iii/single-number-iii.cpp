class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto x: nums){
            mpp[x]++;
        }
        vector<int> res;
        for(auto x: mpp){
            if(x.second == 1){
                res.push_back(x.first);
            }
        }
        return res;
    }
};