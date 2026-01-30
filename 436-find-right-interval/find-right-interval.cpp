class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_map<int,int> pos;
        for(int i = 0; i<n; i++) {
            pos[intervals[i][0]] = i;
        }
        vector<int> res (n,-1);
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i<n; i++) {
            int target = intervals[i][1];
            int lo = i, hi = n-1;
            while(lo<=hi) {
                int mid = lo + (hi - lo)/2;
                if(intervals[mid][0] >= target) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (lo < n && lo >= i) res[pos[intervals[i][0]]] = pos[intervals[lo][0]];
        }
        return res;
    }
};