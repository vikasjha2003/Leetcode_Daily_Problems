class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact;
        fact.push_back(1);
        for(int i = 1; i<=9; i++) {
            int temp = fact.back() * i;
            fact.push_back(temp);
        } 
        long long sum = 0;
        int a = n;
        unordered_map<int,int> freq ;
        while(a>0) {
            int temp = a%10;
            sum += fact[temp];
            freq[temp]++;
            a /= 10;
        }
        if(sum == n) return true;
        else {
            while(sum>0) {
                int temp = sum%10;
                freq[temp]--;
                if(freq[temp] == 0) freq.erase(temp);
                sum /= 10;

            }
            if(freq.size() == 0) return true;
            else return false;
        }
    }
};