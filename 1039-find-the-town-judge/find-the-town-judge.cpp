class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> istrusted (n+1,0);
        unordered_set<int> st;
        for(auto it : trust) {
            st.insert(it[0]);
            istrusted[it[1]]++;
        }
        for(int i = 1; i<n+1; i++) {
            if(istrusted[i] == n-1 && st.find(i) == st.end()) return i;
        }
        return -1;
    }
};