class Solution {
    public int kroot(int l, int k) {
        if(l == 0) return 0;
        if(k == 1) return l;
        if(l == 1) return l;
        
        int low = 2,hi = l;
        
        while(low <= hi) {
            int mid = low + (hi - low) / 2;
            int val = (int)(Math.pow(mid,k));
            if(val == l) return mid;
            else if (val < l) low = mid + 1;
            else hi = mid - 1;
        }
        
        return hi;
    }
    public int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        int cnt = 0;
        
        int lb = kroot(l,k);
        int ub = kroot(r,k);
        
        for(int i = lb; i <= ub ; i++) {
            int p = (int)(Math.pow(i,k));
            if(p >= l && p <= r) cnt++;
        }

        return cnt;
    }
}