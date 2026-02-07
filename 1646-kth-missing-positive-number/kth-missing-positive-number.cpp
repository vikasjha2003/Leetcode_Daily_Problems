class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        for(int j = 1; i<arr.size(); j++) {
            if(arr[i] == j) i++;
            else k--;
            if(k == 0) return j;
        }
        return arr.back() + k;
    }
};