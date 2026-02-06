class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> nums;
        priority_queue<int> pq;
        for(int i = 0; i<profits.size() ; i++) {
            if(capital[i] <= w) {
                pq.push(profits[i]);
            } else {
                nums.push_back({capital[i],profits[i]});
            }
        }
        sort(nums.begin(),nums.end());
        int i = 0;
        while(k-- && !pq.empty()) {
            w += pq.top();
            pq.pop();
            while(i < nums.size() && nums[i][0] <= w) {
                pq.push(nums[i][1]);
                i++;
            }
        }
        return w;
    }
};