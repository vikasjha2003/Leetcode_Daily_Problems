class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char,int> freq;
        for(int i = 0; i<t.length(); i++) {
            freq[t[i]]++;
        }
        int l = 0, r = 0, idx = -1, count = 0, minlen = s.length() + 1;
        while(r < s.length()) {
            if(freq.find(s[r]) != freq.end()) {
                freq[s[r]]--;
                if(freq[s[r]] >= 0) count++;
            }
            while (count == t.length()) {
                if(r - l + 1 < minlen) {
                    idx = l;
                    minlen = r - l + 1;
                }
                if(freq.find(s[l]) != freq.end()) {
                    freq[s[l]]++;
                    if(freq[s[l]] == 1) count--;
                }
                l++;
            }
            r++;
        }
        if(idx == -1) return "";
        return s.substr(idx,minlen);
    }
};