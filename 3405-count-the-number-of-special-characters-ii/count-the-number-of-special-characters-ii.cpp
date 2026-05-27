class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();

        vector<int> pos (123,-1);

        for(int i = 0; i<n; i++) {
            if(islower(word[i])) {
                pos[word[i]] = i;
            } else if (pos[word[i]] == -1) {
                pos[word[i]] = i;
            }
        }

        int i = 'a';
        int j = 'A';

        int res = 0;

        while(i <= 'z') {
            if(pos[i] > -1 && pos[j] > -1 && pos[i] < pos[j]) {
                res++;
            }
            i++;
            j++;
        }

        return res;
    }
};