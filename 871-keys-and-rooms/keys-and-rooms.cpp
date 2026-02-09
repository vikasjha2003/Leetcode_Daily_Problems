class Solution {
public:
    void DFS(vector<vector<int>>& rooms, vector<bool> &visited, int node) {
        for(int i : rooms[node]) {
            if(!visited[i]) {
                visited[i] = true;
                DFS(rooms , visited,i);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited (rooms.size(), false);
        visited[0] = true;
        DFS(rooms,visited,0);
        for(bool check : visited) {
            if(!check) return false;
        }
        return true;
    }
};