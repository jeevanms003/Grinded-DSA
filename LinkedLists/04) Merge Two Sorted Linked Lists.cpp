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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);  // start node
        ListNode* temp = dummy;             // used to build list

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if(list1 != NULL)
            temp->next = list1;

        if(list2 != NULL)
            temp->next = list2;

        return dummy->next;
    }
};

Time Complexity

O(n + m)

n = length of list1
m = length of list2

We iterate through both lists once.

Space Complexity

O(1)

We only use a few extra pointers (dummy, temp).

No extra data structures proportional to input size are used.


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

#include <vector>
#include <algorithm>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;

        // Store values of first list
        while(list1 != NULL){
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        // Store values of second list
        while(list2 != NULL){
            arr.push_back(list2->val);
            list2 = list2->next;
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        // Create new linked list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for(int x : arr){
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return dummy->next;
    }
};