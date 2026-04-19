class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++) {
            pq.push({nums[i],i});
        }

        int stable = INT_MAX;
        int maxi = nums[0];

        for(int i = 0; i<n; i++) {
            if(maxi < nums[i]) maxi = nums[i];
            while(pq.top().second < i) pq.pop();
            stable = min(stable , maxi - pq.top().first);
            if(stable <= k) return i;
        }

        return -1;
    }
};