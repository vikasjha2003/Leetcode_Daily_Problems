class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // Brute Force
        int n = s1.length();
        unordered_map<char,int> odd;
        unordered_map<char,int> even;
        for(int i = 0 ; i < n; i++) {
            if(i % 2 == 0) {
                even[s1[i]]++;
            } else {
                odd[s1[i]]++;
            }         
        }
        for(int i = 0 ; i < n; i++) {
            if(i % 2 == 0) {
                if(even.find(s2[i]) != even.end()) {
                    even[s2[i]]--;
                    if(even[s2[i]] == 0) even.erase(s2[i]);
                } else {
                    return false;
                }
            } else {
                if(odd.find(s2[i]) != odd.end()) {
                    odd[s2[i]]--;
                    if(odd[s2[i]] == 0) odd.erase(s2[i]);
                } else {
                    return false;
                }
            }         
        }
        if(even.empty() && odd.empty()) return true;
        return false;
    }
};