class Solution {

    public Boolean flag (int[] nums, int l, int r) {
        int maxi = nums[l];
        int mini = nums[l];
        Set<Integer> st = new HashSet();
        st.add(nums[l]);

        for(int i = l; i <= r; i++) {
            maxi = Math.max(maxi,nums[i]);
            mini = Math.min(mini,nums[i]);
            st.add(nums[i]);
        }

        if((maxi - mini) % (r - l) != 0) return false;

        int d = (maxi - mini) / (r - l);
        int a = mini + d;

        while(a < maxi) {
            if(!st.contains(a)) return false;
            a += d;
        }

        return true;
    }

    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> ans = new ArrayList<>();

        for(int i = 0; i<l.length; i++) {
            ans.add(flag(nums,l[i],r[i]));
        }

        return ans;
    }

}