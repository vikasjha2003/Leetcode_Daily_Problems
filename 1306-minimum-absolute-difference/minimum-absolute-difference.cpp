class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<vector<int>>> mpp;
        for(int i = 0; i<arr.size()-1; i++) {
            int a = abs(arr[i] - arr[i+1]);
            mpp[a].push_back({arr[i],arr[i+1]});
        }
        auto it = mpp.begin();
        return it->second;
    }
};