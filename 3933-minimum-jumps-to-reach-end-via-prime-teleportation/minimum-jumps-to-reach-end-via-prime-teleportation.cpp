static vector<bool> isPrime = []() {
    vector<bool> s(1e6 + 1,true);
    s[1] = false;
    for(int i = 2; i * i <= 1e6; i++) {
        if(s[i] == true) { 
            for(int j = i * i; j <= 1e6; j += i) {
                if(s[j] == true) s[j] = false;
            }
        }
    }
    return s;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> pt;
        for(int i = 0; i<n; i++) {
            int x = nums[i];
            if(isPrime[x]) {
                pt[x].push_back(i);
            } else {
                for(int j = 2; j*j <= x; j++) {
                    if(x % j == 0) {
                        pt[j].push_back(i);
                        if(j != x/j) {
                            pt[x/j].push_back(i);
                        }
                    }
                }
            }
        }

        vector<char> vis (n,false);

        queue<int> q;
        q.push(0);
        vis[0] = true;

        int cnt = 0;

        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                int idx = q.front();
                q.pop();

                if(idx == n-1) return cnt;
                
                if(idx-1 >= 0 && !vis[idx-1]) {
                    q.push(idx-1);
                    vis[idx-1] = true;
                }

                if(idx+1 < n && !vis[idx+1]) {
                    q.push(idx+1);
                    vis[idx+1] = true;
                }

                if(isPrime[nums[idx]]) {
                    vector<int> &v = pt[nums[idx]];
                    for(int val : v) {
                        if(!vis[val]) {
                            q.push(val);
                            vis[val] = true;
                        }
                    }
                    v.clear();
                }
            }
            cnt++;
        }

        return -1;
    }
};