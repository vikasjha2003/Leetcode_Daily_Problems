class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxi = Integer.MIN_VALUE;
        for(int num : candies) {
            maxi = Math.max(maxi,num);
        }

        List<Boolean> res = new ArrayList<>();

        for(int num : candies) {
            if(num + extraCandies >= maxi) res.add(true);
            else res.add(false);
        }

        return res;
    }
}