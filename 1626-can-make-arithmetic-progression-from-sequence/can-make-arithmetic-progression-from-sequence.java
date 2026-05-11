class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int maxi = arr[0];
        int mini = arr[0];
        Set<Integer> st = new HashSet<>();
        st.add(arr[0]);

        for(int i = 1; i<arr.length; i++) {
            maxi = Math.max(maxi,arr[i]);
            mini = Math.min(mini,arr[i]);
            st.add(arr[i]);
        }

        if((maxi - mini) % (arr.length - 1) != 0) return false;

        int d = (maxi - mini) / (arr.length - 1);
        int curr = mini + d;
        
        while (curr < maxi) {
            if(!st.contains(curr)) return false;
            curr += d;
        }

        return true;
    }
}