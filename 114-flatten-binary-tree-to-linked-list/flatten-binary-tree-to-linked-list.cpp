class Solution {
public:
    void traverse(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        ans.push_back(root->val);
        traverse(root->left,ans);
        traverse(root->right,ans);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<int> v;
        traverse(root,v);
        TreeNode* temp = root;
        temp -> left = NULL;
        for(int i = 1; i<v.size(); i++) {
            TreeNode* Node = new TreeNode(v[i]);
            temp -> right = Node;
            temp = temp -> right;          
        }
    }
};