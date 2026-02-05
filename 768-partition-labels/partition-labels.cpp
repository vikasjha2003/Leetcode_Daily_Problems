class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> interval (26 , vector<int> (2 , -1));
        for(int i = 0; i<s.length(); i++) {
            int key = s[i] - 'a';
            if(interval[key][0] == -1) {
                interval[key][0] = i;
                interval[key][1] = i;
            } else {
                interval[key][1] = i;
            }
        }
        sort(interval.begin(),interval.end());
        vector<vector<int>> merge;
        for(int i = 0; i<26; i++) {
            if(interval[i][0] == -1) continue;
            int start = interval[i][0];
            int end = interval[i][1];
            while( i < 26 && interval[i][0] <= end) {
                if(end < interval[i][1]) {
                    end = interval[i][1];
                }
                i++;
            }
            merge.push_back({start , end});
            i--;
        }
        vector<int> res;
        for(int i = 0; i<merge.size(); i++) {
            res.push_back(merge[i][1] - merge[i][0] + 1);
        }
        return res;
    }
};