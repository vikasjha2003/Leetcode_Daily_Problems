class Solution {
public:
    int N, M, K;
    const int mod = 1e9 + 7;
    int solve (int maxi, int size, int cost, vector<vector<vector<int>>> &dp) {
        if(size == N) {
            if(cost == K) return 1;
            return 0;
        }
        if(dp[maxi][size][cost] != -1) return dp[maxi][size][cost];
        int res = 0;
        for(int i = 1; i <= M; i++) {
            if(i > maxi) {
                if(cost < K) res = (res + solve(i, size +1, cost +1, dp)) % mod;
            } else {
                res = (res + solve(maxi, size+1, cost, dp)) % mod;
            }
        }
        return dp[maxi][size][cost] = res;
    }

    int numOfArrays(int n, int m, int k) {
        N = n ,M = m, K = k;
        vector<vector<vector<int>>> dp (m+1,vector<vector<int>> (n+1, vector<int> (k+1,-1)));
        return solve(0,0,0,dp);
    }
};