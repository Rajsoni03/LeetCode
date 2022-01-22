// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

/*
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:
Input: head = [1,2]
Output: [2,1]


Example 3:
Input: head = []
Output: []


Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        if (head->next->next == nullptr){
            ListNode* newhead = head->next;
            newhead->next = head;
            head->next = nullptr;
            return newhead;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        
        while(p3!=nullptr){
            p2->next = p1;
            
            p1 = p2;
            p2 = p3;
            p3 = p3->next;            
        }
        p2->next = p1;
        head->next = nullptr;
        head = p2;
        return head;
        
    }
};