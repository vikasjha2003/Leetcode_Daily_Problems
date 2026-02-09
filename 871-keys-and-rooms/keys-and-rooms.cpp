class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited (rooms.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i : rooms[node]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        for(bool check : visited) {
            if(!check) return false;
        }
        return true;
    }
};