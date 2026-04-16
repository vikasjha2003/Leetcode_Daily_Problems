class Solution {
public:

    int binary_search (vector<int> &arr, int &target) {
        int lo = 0;
        int hi = arr.size()-1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] == target) return mid;
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for(int &q : queries) { 
            vector<int> &v = mpp[nums[q]];
            int m = v.size();
            if(m == 1) q = -1;
            else {
                int idx = binary_search(v,q);
                int left = abs(q - v[(idx -1 + m) % m]);
                int right = abs(q  - v[(idx +1) % m]);
                int vall = min(left, n - left);
                int valr = min(right, n - right);
                q = min(vall,valr);
            }
        }

        return queries;
    }
};