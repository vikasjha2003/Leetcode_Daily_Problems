class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<pair<int,int>> v;
        // 0 -> negative, 1 -> positive
        for(int i = 0; i<n; i++) {
            if(asteroids[i] > 0) {
                v.push_back({asteroids[i],1});
            } else {
                v.push_back({asteroids[i],0});
            }
        }
        vector<int> res;
        stack<int> st; 
        for(int i = 0; i<n; i++) {
            // 00 , 01 , 11 allowed
            if(st.empty() || st.top() == 0 || st.top() == v[i].second) {
                res.push_back(v[i].first);
                st.push(v[i].second);
            } // 10 collison
            else {
                if(abs(res.back()) == abs(v[i].first)) {
                    res.pop_back();
                    st.pop();
                } else if (abs(res.back()) < abs(v[i].first)) {
                    res.pop_back();
                    st.pop();
                    i--;
                }
            }
        }
        return res;
    }
};