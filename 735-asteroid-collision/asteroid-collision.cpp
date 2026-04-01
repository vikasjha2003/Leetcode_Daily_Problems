class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;
        for(int i = 0; i<n; i++) {
            // -- , -+ , ++ allowed
            if(res.empty() || res.back() < 0 || asteroids[i] > 0) {
                res.push_back(asteroids[i]);
            } // +- collison
            else {
                if(res.back() == abs(asteroids[i])) {
                    res.pop_back();
                } else if (res.back() < abs(asteroids[i])) {
                    res.pop_back();
                    i--;
                }
            }
        }
        return res;
    }
};