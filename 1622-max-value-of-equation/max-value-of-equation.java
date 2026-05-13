class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        int max_val = Integer.MIN_VALUE;
        int l = 0, r = 1;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(b[0],a[0]));

        while(l < points.length-1) {
            while (r < points.length && points[r][0] - points[l][0] <= k) {
                pq.add(new int[] {points[r][0] + points[r][1],r});
                r++;
            }

            int[] maxi = pq.peek();

            while(!pq.isEmpty() && maxi != null && maxi[1] <= l) {
                pq.poll();
                maxi = pq.peek();
            }

            if(maxi != null) {
                max_val = Math.max(max_val, maxi[0] + points[l][1] - points[l][0]);
            }

            l++;

        }

        return max_val;
    }
}