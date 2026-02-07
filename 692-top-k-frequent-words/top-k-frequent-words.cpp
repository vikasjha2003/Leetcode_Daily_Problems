class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string s : words) {
            freq[s]++;
        }
        vector<pair<string,int>> v (freq.begin(), freq.end());
        sort(v.begin(),v.end(), [](pair<string,int> &p1 , pair<string,int> &p2) {
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        });
        vector<string> res;
        for(int i = 0; i<k; i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};