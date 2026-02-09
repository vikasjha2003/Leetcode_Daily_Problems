class Solution {
public:
    int n;
    void Inorder(TreeNode* root, vector<TreeNode*> &inorder) {
        if(!root) return;
        Inorder(root->left , inorder);
        inorder.push_back(root);
        Inorder(root->right , inorder);
    }
    TreeNode* buildtree (vector<TreeNode*> &inorder , int left , int right) {
        if(left > right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode* root = inorder[mid];
        root -> left = buildtree(inorder,left,mid-1);
        root -> right = buildtree(inorder,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        Inorder(root , inorder);
        n = inorder.size();
        return buildtree(inorder,0,n-1);
    }
};