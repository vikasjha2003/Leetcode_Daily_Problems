class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> quad (n, vector<int> (4));
        for(int i = 0; i<n; i++) {
            if(directions[i] == 'R') {
                quad[i] = {positions[i], i, healths[i], 0};
            }else {
                quad[i] = {positions[i], i, healths[i], 1};
            }
        }
        sort(quad.begin(), quad.end());
        stack<int> st;
        vector<pair<int,int>> res;
        for(int i = 0; i<n; i++) {
            if(st.empty() || st.top() == 1 || st.top() == quad[i][3]) {
                st.push(quad[i][3]);
                res.push_back({quad[i][1],quad[i][2]});
            } else {
                if (res.back().second == quad[i][2]) {
                    res.pop_back();
                    st.pop();
                } else if (res.back().second < quad[i][2]) {
                    res.pop_back();
                    st.pop();
                    quad[i][2]--;
                    i--;
                } else {
                    res.back().second = res.back().second -1;
                }
            }
        }
        sort(res.begin(),res.end());
        vector<int> ans;
        for(auto &it : res) {
            ans.push_back(it.second);
        }
        return ans;
    }
};