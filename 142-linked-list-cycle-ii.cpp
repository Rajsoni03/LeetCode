// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

/*
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> st;
        
//         while(head){
//             if (st.find(head) != st.end())
//                 return head;
//             st.insert(head);
//             head = head->next;
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==nullptr || head->next==nullptr) return nullptr;
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        
        while(fast && fast->next){
            if (fast == slow) {
                slow = head;
                while(fast!=slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return nullptr;
    }
};