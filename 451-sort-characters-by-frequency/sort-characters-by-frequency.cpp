class Solution {
public:
    static bool cmp (pair<char,int> &p1 , pair<char,int> &p2) {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c : s) freq[c]++;
        vector<pair<char,int>> ch (freq.begin(),freq.end());
        sort(ch.begin(),ch.end(),cmp);
        string res = "";
        for(int i = 0; i<ch.size(); i++) {
            string str (ch[i].second , ch[i].first);
            res += str;
        }
        return res;
    }
};