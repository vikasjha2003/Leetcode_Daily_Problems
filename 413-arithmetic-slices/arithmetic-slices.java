class Solution {
    // brute force
    public int numberOfArithmeticSlices(int[] arr) {
        if(arr.length < 3) return 0;

        int ans = 0;

        for(int i = 0; i<arr.length - 2; i++) {
            int x = arr[i+1] - arr[i];
            for(int j = i+2; j<arr.length; j++) {
                if(arr[j] - arr[j-1] != x) {
                    break;
                }
                ans++;
            }
        }

        return ans;
    }
}