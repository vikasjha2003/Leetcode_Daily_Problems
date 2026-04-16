class Solution {
public:

    // Should accept but with a very poor complexity.

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for(int &q : queries) { 
            int m = mpp[nums[q]].size();
            if(m == 1) q = -1;
            else {
                int lo = 0;
                int hi = m - 1;
                int mid;
                while(lo <= hi) {
                    mid = lo + (hi - lo) / 2;
                    if(mpp[nums[q]][mid] == q) break;
                    else if (mpp[nums[q]][mid] > q) hi = mid - 1;
                    else lo = mid + 1;
                }
                int left = mpp[nums[q]][(mid -1 + m) % m];
                int right = mpp[nums[q]][(mid+1) % m];
                int vall = min(abs(q - left), n - abs(q-left));
                int valr = min(abs(q - right), n - abs(q-right));
                q = min(vall,valr);
            }
        }

        return queries;
    }
};