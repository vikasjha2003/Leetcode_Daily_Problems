class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); 
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int f = 0;
                bool balanced = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (f == 0) f = freq[k];
                        else if (freq[k] != f) {
                            balanced = false;
                            break;
                        }
                    }
                }

                if (balanced)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
