class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> pos;
        for(int i = 0; i<n; i++) {
            pos.push_back({intervals[i][0],i});
        }
        vector<int> res (n,-1);
        sort(pos.begin(),pos.end());
        for(int i = 0; i<n; i++) {
            int target = intervals[i][1];
            int lo = 0, hi = n-1;
            while(lo<=hi) {
                int mid = lo + (hi - lo)/2;
                if(pos[mid].first >= target) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (lo < n) res[i] = pos[lo].second;
        }
        return res;
    }
};