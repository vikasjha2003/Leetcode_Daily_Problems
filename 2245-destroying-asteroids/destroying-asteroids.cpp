class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        for(int i = 0; i<n; i++) {
            if(mass >= 1e5) return true;
            else if(asteroids[i] <= mass) mass += asteroids[i];
            else return false;
        }
        return true;
    }
};