class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

Step-by-step Method ✅
Step 1: Count how many times function runs

Function runs once for each node

If tree has n nodes

👉 Function calls = n

Step 2: Work per node

Inside function:

countNodes(root->left)   -> recursive call
1                        -> constant work
countNodes(root->right)  -> recursive call

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