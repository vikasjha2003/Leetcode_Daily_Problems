class Solution {
public:

    const int mod = 1e9 + 7;

    long long myPow(long long base, long long exp) {
        if(exp == 1) return base;    
        long long ans = 1;
        while (exp > 0) {
            if(exp % 2 == 1) ans = ans * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return ans;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        int last = 0;
        vector<pair<int,int>> nums;
        for(int i = 0; i<n; i++) {
            if(nums0[i] == 0) last += nums1[i];
            else nums.push_back({nums1[i],nums0[i]});
        }

        sort(nums.begin(),nums.end(), [](auto &p1, auto &p2) {    
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        });

        long long res = 0;
        for(int i = 0; i < last; i++) { // ones
            res = (res*2 + 1) % mod;
        }

        for(int i = 0; i<nums.size(); i++) {
            auto &it = nums[i];
            for(int i = 0; i < it.first; i++) { // ones
                res = (res*2 + 1) % mod;

            }
            for(int i = 0; i < it.second; i++) { // twos
                res = (res*2) % mod;
            }
        }
        return res;
    }
};