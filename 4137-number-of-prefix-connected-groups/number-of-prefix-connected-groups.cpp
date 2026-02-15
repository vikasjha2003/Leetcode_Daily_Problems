class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int max_count = 0;
        unordered_map<string,int> mpp;
        for(int i = 0; i<words.size(); i++) {
            if(words[i].length() >= k) 
                mpp[words[i].substr(0,k)]++;
        }
        for(auto it : mpp) {
            if(it.second >= 2) max_count++;
        }
        return max_count;
    }
};