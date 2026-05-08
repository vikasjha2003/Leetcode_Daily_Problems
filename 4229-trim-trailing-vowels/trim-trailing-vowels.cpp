class Solution {
public:
    bool isVowel(char &c) {
        if(c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e') {
            return true;
        }
        return false;
    }
    string trimTrailingVowels(string s) {
        while(s.length() > 0) {
            if(isVowel(s.back())) {
                s.pop_back();
            }
            else return s;
        }
        return s;
    }
};