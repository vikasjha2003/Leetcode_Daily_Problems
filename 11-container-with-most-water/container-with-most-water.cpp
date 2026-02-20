class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right) {
            int cursum = min(height[left],height[right])*(right-left);
            maxwater = max(cursum,maxwater);
            if(height[left]<height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxwater;
    }
};