class Solution {
    private boolean isVowel (char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    public String trimTrailingVowels(String s) {
        StringBuilder sb = new StringBuilder(s);

        while(sb.length() > 0) {
            if(isVowel(sb.charAt(sb.length() -1))) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                return sb.toString();
            }
        }

        return sb.toString();
    }
}