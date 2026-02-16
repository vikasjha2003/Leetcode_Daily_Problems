class Solution {
public:
    string add (string num1, string num2) {
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
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num2.length();
        int m = num1.length();
        string res = "";
        for(int i = n-1; i >= 0; i--) {
            int a = num2[i] - 48;
            int carry = 0;
            string cur = "";
            int j = m-1;
            while(j >= 0 || carry) {
                if(j >= 0) {
                    int b = num1[j] - 48;
                    carry += b * a;
                    j--;
                }
                cur += carry % 10 + 48;
                carry /= 10;
            }
            reverse(cur.begin(), cur.end());
            string c (n-i-1,'0');
            cur += c;
            res = add(res,cur);
        }
        return res;
    }
};