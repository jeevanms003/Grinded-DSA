class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // if fast becomes NULL, remove head
        if(fast == NULL) {
            return head->next;
        }

        // move both pointers
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete nth node from end
        slow->next = slow->next->next;

        return head;
    }
};

Time Complexity

O(n)

Fast pointer travels n nodes.
Slow pointer travels n nodes.
Both traverse the list once.

Space Complexity

O(1)

Only two pointers are used.
No extra memory proportional to input size.



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode* temp = head;

        // Step 1: Count total nodes
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: If head needs to be removed
        if(count == n) {
            return head->next;
        }

        // Step 3: Find node before the one to delete
        temp = head;
        for(int i = 1; i < count - n; i++) {
            temp = temp->next;
        }

        // Step 4: Delete node
        temp->next = temp->next->next;

        return head;
    }
};