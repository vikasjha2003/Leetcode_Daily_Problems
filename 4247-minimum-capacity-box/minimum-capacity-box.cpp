class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1;
        for(int i = 0; i< capacity.size(); i++) {
            if(capacity[i] >= itemSize) {
                if(idx == -1) idx = i;
                else if (capacity[i] < capacity[idx]) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};