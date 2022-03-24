// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while(p2 && p2->next){
            if (p2->val == p2->next->val){
                ListNode *temp = p2->next;
                while(temp && temp->val == p2->val){
                    temp = temp->next;            
                }
                    
                if (p2->val == head->val) head = temp;
                p2 = temp;
                p1->next = temp;
            }
            else{
                p1 = p2;
                p2 = p2->next; 
            }
        }
        p1->next = p2;
        return head;
    }
};