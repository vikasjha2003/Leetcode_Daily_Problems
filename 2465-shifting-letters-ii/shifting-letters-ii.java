class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        StringBuilder sb = new StringBuilder(s);
        int[] diff = new int[s.length()];

        for(int[] q : shifts) {
            int a = 1;
            if(q[2] == 0) a = -1;
            diff[q[0]] += a;
            if(q[1] + 1 < diff.length) diff[q[1] + 1] -= a; 
        }

        int cumsum = 0;

        for(int i = 0; i<diff.length; i++) {
            cumsum += diff[i];
            int a = cumsum + (sb.charAt(i) - 'a');
            int mod = (a % 26 + 26) % 26;
            sb.setCharAt(i,(char)(mod + 'a'));
        }

        return sb.toString();
    }
}