class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        while(i>=0 || j>=0 || carry) {
            if(i >= 0) {
                carry += a[i] - 48;
                i--;
            }
            if(j >= 0) {
                carry += b[j] - 48;
                j--;
            }
            res += carry%2 + 48;
            carry /= 2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};