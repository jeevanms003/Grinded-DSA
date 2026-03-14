class Solution {
public:
    
    int prev = -1;
    int ans = INT_MAX;

    void inorder(TreeNode* root)
    {
        if(root == NULL) return;

        inorder(root->left);

        if(prev != -1)
            ans = min(ans, root->val - prev);

        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};



class Solution {
public:

    void dfs(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL)
            return;

        arr.push_back(root->val);

        dfs(root->left, arr);
        dfs(root->right, arr);
    }

    int getMinimumDifference(TreeNode* root) {

        vector<int> arr;

        dfs(root, arr);

        sort(arr.begin(), arr.end());

        int ans = INT_MAX;

        for(int i = 1; i < arr.size(); i++)
        {
            ans = min(ans, arr[i] - arr[i-1]);
        }

        return ans;
    }
};