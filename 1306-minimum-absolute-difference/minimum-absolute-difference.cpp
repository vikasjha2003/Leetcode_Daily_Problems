class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> pairs;
        int mina = INT_MAX;
        for(int i = 0; i<arr.size()-1; i++) {
            int a = abs(arr[i] - arr[i+1]);
            if(a < mina) {
                mina = a;
                pairs.clear();
                pairs.push_back({arr[i],arr[i+1]});
            }
            else if(mina == a) {
                pairs.push_back({arr[i],arr[i+1]});
            }
        }
        return pairs;
    }
};