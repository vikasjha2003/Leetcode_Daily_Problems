class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        while(i>=0 || j >=0 || carry) {
            if(i >= 0) {
                carry += num1[i] - 48;
                i--;
            }
            if(j >= 0) {
                carry += num2[j] - 48;
                j--;
            }
            res += carry%10 + 48;
            carry /= 10;
        }
        reverse(res.begin(),res.end());
        return res;        
    }
};