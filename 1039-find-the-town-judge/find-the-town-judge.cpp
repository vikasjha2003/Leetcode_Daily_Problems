class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> istrusted (n+1,0);
        vector<bool> trusts (n+1,false);
        for(auto &it : trust) {
            trusts[it[0]] = true;
            istrusted[it[1]]++;
        }
        for(int i = 1; i<n+1; i++) {
            if(istrusted[i] == n-1 && trusts[i] == false) return i;
        }
        return -1;
    }
};