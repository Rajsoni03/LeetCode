// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:
The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if (!root) return ans;
            
        stack<TreeNode*> s1, s2;
        
        TreeNode* n = root;
        s1.push(n);
        
        while(!s1.empty()){
            n = s1.top();
            s2.push(n);
            s1.pop();
            if (n->left) s1.push(n->left);
            if (n->right) s1.push(n->right);
        }
        
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }        
        
        return ans;
        
    }
};