class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex] == target) return 0;
        int n = words.size();
        int right = (startIndex + 1) % n , left = (startIndex - 1 + n) % n;
        int cntr = 1;
        int cntl = 1;
        int res = n+1;
        while(right != startIndex || left != startIndex) {
            if(right != startIndex) {
                if(words[right] == target) {
                    res = min(res,cntr);
                }
                right = (right + 1) % n;
            }
            if(left != startIndex) {
                if(words[left] == target) {
                    res = min(res,cntl);
                }
                left = (left - 1 + n) % n;
            }
            cntr++;
            cntl++;
        }
        if(res == n+1) return -1;
        return res;
    }
};