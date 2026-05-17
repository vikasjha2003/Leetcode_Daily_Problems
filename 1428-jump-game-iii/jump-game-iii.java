class Solution {

    public boolean solve(int[] arr, int idx, boolean[] visited) {
        if(idx < 0 || idx >= arr.length || visited[idx]) return false;
        if(arr[idx] == 0) return true;

        visited[idx] = true;
        
        return solve(arr,idx - arr[idx],visited) || solve(arr,idx + arr[idx],visited);
    }

    public boolean canReach(int[] arr, int start) {
        boolean[] visited = new boolean[arr.length];
        return solve(arr,start,visited);
    }

}