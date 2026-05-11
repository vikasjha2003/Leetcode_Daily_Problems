class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int cur = capacity;
        int res = 0;

        for(int i = 0; i<plants.length; i++) {          
            if(plants[i] > cur) {
                cur = capacity;
                res += (i)*2;
            }
            cur -= plants[i];  
            res++;
        }

        return res;
    }
}