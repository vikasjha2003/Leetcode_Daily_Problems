class Solution {
    void reverse(int i , int j, char[] s) {
        if(i >= j) return;
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverse(i+1, j-1,s);
    }
    public void reverseString(char[] s) {
        reverse(0,s.length - 1,s);        
    }
}