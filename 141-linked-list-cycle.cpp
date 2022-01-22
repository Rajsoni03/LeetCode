// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

/*
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
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
/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> st;
        
        while(head && head->next){
            if (st.find(head)!=st.end()) return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        
        while(head && head->next){
            if (st.find(head)!=st.end()) return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};