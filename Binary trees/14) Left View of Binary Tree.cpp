class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        
        vector<int> result;
        if(root == NULL)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i++) {
                
                TreeNode* node = q.front();
                q.pop();
                
                // First node of this level
                if(i == 0)
                    result.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return result;
    }
};