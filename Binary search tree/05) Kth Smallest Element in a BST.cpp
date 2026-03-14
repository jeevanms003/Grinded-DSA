class Solution {
public:
    int ans = 0;
    int cnt = 0;

    void inorder(TreeNode* root, int k)
    {
        if(root == NULL) return;

        inorder(root->left, k);

        cnt++;
        if(cnt == k)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
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

    int kthSmallest(TreeNode* root, int k) {

        vector<int> arr;

        dfs(root, arr);

        sort(arr.begin(), arr.end());

        return arr[k-1];
    }
};