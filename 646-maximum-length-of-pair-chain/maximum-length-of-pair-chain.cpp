class Solution {
public:
int n;
    int solve (vector<vector<int>>& pairs, int idx, int last, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][last + 1000] != -1) return dp[idx][last + 1000];
        
        int skip = solve(pairs,idx+1,last,dp);

        int take = 0;
        if(last == -1 || pairs[idx][0] > pairs[last][1]) take = 1 + solve(pairs,idx+1,idx,dp);
        
        return dp[idx][last + 1000] = max(skip,take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        vector<vector<int>> dp (n, vector<int> (2001,-1));
        sort(pairs.begin(), pairs.end());
        return solve(pairs,0,-1,dp);
    }
};