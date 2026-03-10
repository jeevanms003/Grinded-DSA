#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    inorder(root);
    cout<<endl;

    preorder(root);
    cout<<endl;

    postorder(root);

    return 0;
}

🌳 1️⃣ Time Complexity Calculation

Example (Inorder Traversal):

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> result;
        postorder(root, result);
        
        return result;
    }
    
    void postorder(TreeNode* root, vector<int>& result)
    {
        if(root == NULL)
            return;
            
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};
Step-by-step Method ✅
Step 1: Count how many times function runs

Function runs once for each node

If tree has n nodes

👉 Function calls = n

Step 2: Work per node

Inside function:

inorder(root->left)   -> recursive call
cout << root->data    -> O(1)
inorder(root->right)  -> recursive call

Each node does constant work O(1)

Final Time Complexity
T(n) = n × O(1)

T(n) = O(n)

✅ Traversal always = O(n)

Because every node is visited exactly once



🌳 2️⃣ Space Complexity Calculation

Binary trees use recursion stack memory

We calculate maximum recursive calls at same time

That equals height of tree (h)

Space = O(h)
Case 1: Balanced Tree

Example:

        1
      /   \
     2     3
    / \   / \

Height:

h = log n

Space:

O(log n)
Case 2: Worst Case (Skewed Tree)

Example:

1
 \
  2
   \
    3
     \
      4

Height:

h = n

Space:

O(n)
⭐ Final Answer (OA Style)
Time Complexity
O(n)

Reason:

Each node is visited exactly once.

Space Complexity
O(h)

where:

h = height of tree

Worst case:

O(n)

Balanced tree:

O(log n)