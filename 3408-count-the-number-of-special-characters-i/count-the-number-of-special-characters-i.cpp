class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();

        vector<int> freq (128,0);

        for(int i = 0; i<n; i++) {
            freq[word[i]]++;
        }

        int i = 'a';
        int j = 'A';

        int res = 0;

        while(i <= 'z') {
            if(freq[i] > 0 && freq[j] > 0) {
                res++;
            }
            i++;
            j++;
        }

        return res;
    }
};