class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int cnt = 0;
        int dist = 0;
        for(int i = 0; i<n; i++) {
            if(moves[i] == '_') cnt++;
            else if (moves[i] == 'R') dist++;
            else dist--;
        }
        return abs(dist) + cnt;
    }
};