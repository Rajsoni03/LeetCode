// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

/*
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
                
        int sum = temp1->val + temp2->val;
        int carry = sum/10;
                
        ListNode *head = new ListNode(sum%10);
        ListNode *end = head;
        
        temp1 = temp1->next;
        temp2 = temp2->next;
        
        while (temp1 != nullptr && temp2 != nullptr){
            sum = (temp1->val + temp2->val + carry);
            carry = sum/10;
            ListNode *n = new ListNode(sum%10);
            end->next = n;            
            end = end->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (temp1 != nullptr){
            sum = temp1->val + carry;
            carry = sum / 10;
            ListNode *n = new ListNode(sum%10);
            end->next = n;            
            end = end->next;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr){
            sum = temp2->val + carry;
            carry = sum / 10;
            ListNode *n = new ListNode(sum%10);
            end->next = n;            
            end = end->next;
            temp2 = temp2->next;
        }
        if (carry){
            ListNode *n = new ListNode(carry);
            end->next = n;   
        }
        return head;        
    }
};