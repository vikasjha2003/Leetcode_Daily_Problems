class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int cnt = 0;

        int idx = 0;
        if (ruleKey.equals("color")) idx = 1;
        if (ruleKey.equals("name")) idx = 2;


        for(int i = 0; i<items.size(); i++) {
            if(items.get(i).get(idx).equals(ruleValue)) {
                cnt++;
            }
        }

        return cnt;
    }
}