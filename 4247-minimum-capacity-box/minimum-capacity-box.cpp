class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int res = 101;
        int idx = -1;
        for(int i = 0; i< capacity.size(); i++) {
            if(capacity[i] >= itemSize && capacity[i] < res) {
                res = capacity[i];
                idx = i;
            }
        }
        return idx;
    }
};