class Solution {
public:
    int m , n;
    int solve(string &text1, string &text2, int idx1, int idx2, vector<vector<int>> &dp) {
        if(idx1 == m) return 0;
        if(idx2 == n) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(text1[idx1] == text2[idx2]) return dp[idx1][idx2] = 1 + solve(text1,text2, idx1 + 1, idx2 + 1, dp);
        else {
            int first = solve(text1,text2, idx1 + 1, idx2, dp);
            int second = solve(text1,text2, idx1, idx2 + 1, dp);
            return dp[idx1][idx2] = max(first,second);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();

        vector<vector<int>> dp (m, vector<int> (n,-1));

        return solve(text1,text2,0,0,dp);
    }
};