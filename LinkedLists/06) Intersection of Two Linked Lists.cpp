#include <unordered_map>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, int> mp;

        // store nodes of list A
        ListNode* temp = headA;
        while(temp != NULL) {
            mp[temp] = 1;
            temp = temp->next;
        }

        // check nodes of list B
        temp = headB;
        while(temp != NULL) {
            if(mp.find(temp) != mp.end()) {
                return temp;   // intersection node
            }
            temp = temp->next;
        }

        return NULL;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* a = headA;

        while(a != NULL) {
            ListNode* b = headB;

            while(b != NULL) {
                if(a == b) {
                    return a;   // intersection found
                }
                b = b->next;
            }

            a = a->next;
        }

        return NULL; // no intersection
    }
};
