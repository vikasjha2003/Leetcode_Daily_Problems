class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> check(101,false);
        for(int i : bulbs) {
            check[i] = !check[i];
        }
        vector<int> res;
        for(int i = 0; i<101; i++) {
            if(check[i]) res.push_back(i);
        }
        return res;
    }
};