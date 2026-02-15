class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<char> mpp (26);
        for(int i = 0; i<26; i++) {
            mpp[i] = 'z' - i;
        }
        string res = "";
        for(string word : words) {
            int sum = 0;
            for(char c : word) {
                sum += weights[c-'a'];
            }
            res.push_back(mpp[sum%26]);
        }
        return res;
    }
};