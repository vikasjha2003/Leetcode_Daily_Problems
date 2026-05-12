class Solution {
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks, (a,b) -> Integer.compare(b[1] - b[0] , a[1] - a[0]));

        int sum = 0;        

        for(int i = 0; i<tasks.length; i++) {
            sum += tasks[i][0];
        }

        int res = sum;

        for(int i = 0; i<tasks.length; i++) {
            if(sum < tasks[i][1]) {
                res += tasks[i][1] - sum;
                sum = tasks[i][1];
            }
            sum -= tasks[i][0];
        }

        return res;
    }
}