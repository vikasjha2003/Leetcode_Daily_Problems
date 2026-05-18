class Solution {
    public int minJumps(int[] arr) {
        if(arr.length == 1) return 0;

        HashMap<Integer,ArrayList<Integer>> pos = new HashMap<>();
        for(int i = 0; i<arr.length; i++) {
            pos.putIfAbsent(arr[i], new ArrayList<>());
            pos.get(arr[i]).add(i);
        }

        boolean[] visited = new boolean[arr.length];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0] = true;

        int steps = 0;
        
        while(!q.isEmpty()) {
            int size = q.size();

            while(size-- > 0) {
                int idx = q.poll();
                if(idx == arr.length - 1) return steps;

                if(idx - 1 >= 0 && !visited[idx-1]) {
                    q.offer(idx-1);
                    visited[idx - 1] = true;
                }
                if(idx + 1 < arr.length && !visited[idx+1]) {
                    q.offer(idx+1);
                    visited[idx + 1] = true;
                }

                for(int val : pos.get(arr[idx])) {
                    if(visited[val] != true) {
                        q.offer(val);
                        visited[val] = true;
                    }
                }
                pos.get(arr[idx]).clear();
            }

            steps++;
        }

        return -1;
    }
}