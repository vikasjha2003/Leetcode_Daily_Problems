class Solution {

    public int[] copyOf (int[] nums, int l, int r) {
        int[] arr = new int[r-l+1];
        for(int i = 0; i < arr.length; i++) {
            arr[i] = nums[i+l];
        }
        return arr;
    }

    public Boolean flag (int[] arr) {
        int maxi = arr[0];
        int mini = arr[0];
        Set<Integer> st = new HashSet();
        st.add(arr[0]);

        for(int i = 1; i<arr.length; i++) {
            maxi = Math.max(maxi,arr[i]);
            mini = Math.min(mini,arr[i]);
            st.add(arr[i]);
        }

        if((maxi - mini) % (arr.length - 1) != 0) return false;

        int d = (maxi - mini) / (arr.length - 1);
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
            int[] arr = copyOf(nums,l[i],r[i]);
            ans.add(flag(arr));
        }

        return ans;
    }

}