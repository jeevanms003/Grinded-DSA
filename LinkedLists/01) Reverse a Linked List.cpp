/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

Time Complexity

The time complexity is O(n), where n is the number of nodes in the linked list.
The algorithm traverses the linked list only once using a while loop.
During each iteration, only constant-time pointer operations are performed.
Therefore, the total running time grows linearly with the number of nodes.

Space Complexity

The space complexity is O(1) (constant space).
The algorithm uses only three extra pointers: prev, curr, and nextNode.
No additional data structures or memory proportional to input size are used.
Thus, the reversal is done in-place without extra memory.