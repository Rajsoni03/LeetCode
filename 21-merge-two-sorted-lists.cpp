// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

/*
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        
        while (l1 && l2){
            if (l1->val < l2->val){
                if (head) { tail->next = l1; tail = tail->next; }
                else { head = tail = l1; }   
                l1 = l1->next;
            }
            else { 
                if (head) { tail->next = l2; tail = tail->next; }
                else { head = tail = l2; }
                l2 = l2->next;
            }
        }
        if (l1){ if (head) tail->next = l1; else head = tail = l1;}
        if (l2){ if (head) tail->next = l2; else head = tail = l2;}
        
        return head;
    }
};