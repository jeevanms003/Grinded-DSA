/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) 
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    bool isMirror(TreeNode* left, TreeNode* right){
        
        if(left == NULL && right == NULL)
            return true;
        
        if(left == NULL || right == NULL)
            return false;
        
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        return isMirror(root->left, root->right);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        queue<TreeNode*> q;
        
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if(left == NULL && right == NULL)
                continue;
                
            if(left == NULL || right == NULL)
                return false;
                
            if(left->val != right->val)
                return false;
            
            q.push(left->left);
            q.push(right->right);
            
            q.push(left->right);
            q.push(right->left);
        }
        
        return true;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        queue<TreeNode*> q1, q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty()){
            
            TreeNode* n1 = q1.front();
            TreeNode* n2 = q2.front();
            
            q1.pop();
            q2.pop();
            
            // Both NULL
            if(n1 == NULL && n2 == NULL)
                continue;
            
            // One NULL
            if(n1 == NULL || n2 == NULL)
                return false;
            
            // Values mismatch
            if(n1->val != n2->val)
                return false;
            
            // Mirror insertion
            q1.push(n1->left);
            q2.push(n2->right);
            
            q1.push(n1->right);
            q2.push(n2->left);
        }
        
        return true;
    }
};