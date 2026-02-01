class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group) {
        if(hand.size() % group != 0) return false;
        unordered_map<int,int> freq;
        priority_queue<int , vector<int> , greater<int>> mini;
        for(int i : hand) {
            freq[i]++;
            mini.push(i);
        }
        while(freq.size() > 0) {
            if(freq.find(mini.top()) != freq.end()) {
                int a = mini.top();
                for(int i = 1; i<= group; i++) {
                    if(freq.find(a) == freq.end()) return false;
                    freq[a]--;
                    if(freq[a] == 0) freq.erase(a);
                    a++;
                }
            }
            mini.pop();
        }
        return true;
    }
};