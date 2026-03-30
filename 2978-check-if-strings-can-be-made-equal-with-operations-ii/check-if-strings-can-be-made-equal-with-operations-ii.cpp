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
                even[s2[i]]--;
                if(even[s2[i]] == 0) even.erase(s2[i]);
                if(even[s1[i]] == 0) even.erase(s1[i]);
            } else {
                odd[s1[i]]++;
                odd[s2[i]]--;
                if(odd[s2[i]] == 0) odd.erase(s2[i]);
                if(odd[s1[i]] == 0) odd.erase(s1[i]);
            }         
        }
        if(even.empty() && odd.empty()) return true;
        return false;
    }
};