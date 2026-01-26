class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> pairs;
        int mina = INT_MAX;
        for(int i = 0; i<arr.size()-1; i++) {
            int a = abs(arr[i] - arr[i+1]);
            mina = min(mina,a);
        }
        for(int i = 0; i<arr.size()-1; i++) {
            int a = abs(arr[i] - arr[i+1]);
            if(a == mina) pairs.push_back({arr[i],arr[i+1]});
        }
        return pairs;
    }
};