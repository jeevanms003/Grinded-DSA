/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          
            fast = fast->next->next;    

            if (slow == fast) {
                return true;            
            }
        }

        return false;                   
    }
};

Time Complexity

O(n)

In the worst case, both pointers traverse the linked list.

Each node is visited at most a constant number of times.

Therefore the time complexity is linear in the number of nodes (n).

Space Complexity

O(1)

Only two pointers (slow and fast) are used.

No extra data structures are required.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_map>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;

        ListNode* temp = head;

        while (temp != NULL) {
            if (visited[temp] == true) {
                return true;
            }

            visited[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};