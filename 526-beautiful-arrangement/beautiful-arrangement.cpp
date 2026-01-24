class Solution {
public:
    void helper(int pos, int n, vector<bool>& used, int & count) {
        if(pos > n) {
            count++;
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                helper(pos + 1, n, used, count);
                used[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> used(n+1, false);
        int count = 0;
        helper(1, n, used, count);
        return count;
    }
};
