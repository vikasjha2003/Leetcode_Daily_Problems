class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int res = 0;
        for(int i = 0; i<n; i++) {
            vector<int> freq (26,0);
            int maxi = 0;
            for(int j = i; j<n; j++) {
                int key = s[j] - 'a';
                freq[key]++;
                int mini = INT_MAX;
                for(int k = 0; k<26; k++) {
                    if(freq[k] != 0) mini = min(mini,freq[k]);
                }
                maxi = max(maxi,freq[key]);
                res += maxi - mini;
            }
        }
        return res;
    }
};