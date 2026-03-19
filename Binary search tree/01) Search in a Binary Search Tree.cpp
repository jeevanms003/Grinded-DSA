class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == NULL) return NULL;
        
        if(root->val == val) return root;
        
        if(val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

Time Complexity:
The algorithm follows only one path from the root to a node because of the Binary Search Tree property.

Best Case: O(1) when the value is at the root.

Average Case: O(log n) when the BST is balanced.

Worst Case: O(n) when the BST is skewed (like a linked list).

Overall: O(h) where h = height of the tree.

Space Complexity:
The function uses recursion, so the recursion stack can go up to the height of the tree.

Average Case: O(log n)

Worst Case: O(n)

Overall: O(h).