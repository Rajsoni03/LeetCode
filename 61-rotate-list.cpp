// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

/*
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        
        // count len of the list
        ListNode* temp = head;        
        int len = 0;
        while(temp!=nullptr){ temp = temp->next; len++;}
        
        // calculate the point to split
        int breakPoint = len - (k%len) - 1;
        
        // set newhead to break point
        temp = head;
        while(breakPoint--){ temp = temp->next; }
        if (temp->next == nullptr) return head;
        ListNode* newhead = temp->next;
        temp->next = nullptr;
        
        // add old head to tail of newlist
        temp = newhead; 
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = head;
        
        return newhead;
    }
};