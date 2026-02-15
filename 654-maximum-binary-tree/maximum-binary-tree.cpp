class Solution {
public:
    TreeNode* buildtree (vector<int> & nums, int start , int end) {
        if(start > end) return NULL;
        int maxi = start;
        for(int i = start; i<=end; i++) {
            if(nums[maxi] < nums[i]) maxi = i;
        }
        TreeNode* root = new TreeNode(nums[maxi]);
        root -> left = buildtree(nums,start,maxi - 1);
        root -> right = buildtree(nums,maxi + 1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildtree(nums,0,nums.size()-1);
    }
};