class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(char &c : s) {
            freq[c]++;
        }
        bool flag = false;
        int res = 0;
        for(auto &it : freq) {
            if(it.second % 2 == 0) res += it.second;
            else {
                res += it.second - 1;
                flag = true;
            }
        }   
        if(flag) res++;
        return res;
    }
};