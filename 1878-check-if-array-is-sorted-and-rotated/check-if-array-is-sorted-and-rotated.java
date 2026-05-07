class Solution {
    public boolean check(int[] arr) {
        int n = arr.length;
        boolean flag = false;
        
        if(arr[0] < arr[n-1]) flag = true;

        for(int i = 0; i<n-1; i++) {
            if(arr[i+1] < arr[i]) {
                if(flag == false) {
                    flag = true;
                } else return false;
            }
        }

        return true;
    }
}