class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0 , j = tokens.size() - 1;
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int maxscore = 0;
        while (i <= j) {
            while(i <= j && tokens[i] <= power) {
                score++;
                power -= tokens[i];
                i++;
            }
            if(score > maxscore) maxscore = score;
            if(score > 0) {
                power += tokens[j];
                score--;
            }
            j--;
        }
        return maxscore;
    }
};