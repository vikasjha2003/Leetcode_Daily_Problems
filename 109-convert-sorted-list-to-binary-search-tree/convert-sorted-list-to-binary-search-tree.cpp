class Solution {
public:
    TreeNode* buildtree (vector<int> &inorder , int left , int right) {
        if(left > right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root -> left = buildtree(inorder,left,mid-1);
        root -> right = buildtree(inorder,mid+1,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head -> next) return new TreeNode(head -> val);
        vector<int> inorder;
        while(head) {
            inorder.push_back(head->val);
            head = head -> next;
        }
        return buildtree(inorder,0,inorder.size() - 1);
    }
};