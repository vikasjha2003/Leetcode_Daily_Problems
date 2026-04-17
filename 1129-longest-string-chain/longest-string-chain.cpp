class Solution {
public:

    int n;

    bool is_predecessor (string &s1, string &s2) {
        if(s2.length() - s1.length() != 1) return false;
        int i = 0, j = 0;
        bool flag = false;
        while(i < s1.size()) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                if(flag) return false;
                flag = true;
                j++;
            }
        }
        return true;
    }

    int solve (vector<string>& words, int idx, int last, vector<vector<int>> &dp) {
        if(idx == n) return 0;
        if(dp[idx][last + 1] != -1) return dp[idx][last + 1];

        int skip = solve(words,idx+1,last,dp);

        int take = 0;
        if(last == -1 || is_predecessor(words[last],words[idx])) 
            take = 1 + solve(words,idx+1,idx,dp);

        return dp[idx][last + 1] = max(skip,take);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        vector<vector<int>> dp (n,vector<int> (n+1,-1));

        sort(words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.length() < s2.length();
        });

        return solve(words,0,-1,dp);
    }
};