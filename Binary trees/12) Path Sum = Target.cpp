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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    void dfs(TreeNode* root, int sum, vector<int>& arr){
        
        if(root == NULL)
            return;

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            arr.push_back(sum);
            return;
        }

        dfs(root->left, sum, arr);
        dfs(root->right, sum, arr);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        vector<int> arr;

        dfs(root, 0, arr);

        for(int x : arr){
            if(x == targetSum)
                return true;
        }

        return false;
    }
};