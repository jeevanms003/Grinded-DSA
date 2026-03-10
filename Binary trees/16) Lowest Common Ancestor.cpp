class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case
        if(root == NULL || root == p || root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // Case 1: Left is NULL → answer is on right
        if(left == NULL)
            return right;
        
        // Case 2: Right is NULL → answer is on left
        if(right == NULL)
            return left;
        
        // Case 3: Both not NULL → this is LCA
        return root;
    }
};