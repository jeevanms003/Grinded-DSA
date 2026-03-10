/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    int maxSum = INT_MIN;   // Stores final answer
    
    int dfs(TreeNode* node) {
        
        if(node == NULL)
            return 0;
        
        // Get max contribution from left subtree
        int leftGain = dfs(node->left);
        
        // Get max contribution from right subtree
        int rightGain = dfs(node->right);
        
        // Ignore negative contributions
        leftGain = max(0, leftGain);
        rightGain = max(0, rightGain);
        
        // Path that passes through current node
        int pathThroughNode = node->val + leftGain + rightGain;
        
        // Update global maximum
        maxSum = max(maxSum, pathThroughNode);
        
        // Return max single branch to parent
        return node->val + max(leftGain, rightGain);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};