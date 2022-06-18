// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
/*
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.

 Example 1:
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Example 2:
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
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

// Solution 1 : with static variables
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        static int sum = 0;
        static int temp = root->val; 
        
        if (!root->left && !root->right){ 
            // cout << "leaf - " << root->val << ", "<< temp << ", " << sum << endl; 
            sum += temp;
            return root->val;
        }
        
        if (root->left) {
            // cout << "pre  - " << root->val << ", "<< temp << ", " << sum << endl; 
            temp = (temp*10) + root->left->val;
            sumNumbers(root->left);
            temp /= 10;
            // cout << "post - " << root->val << ", "<< temp << ", " << sum << endl; 
        }
        
        if (root->right) {
            // cout << "pre  - " << root->val << ", "<< temp << ", " << sum << endl; 
            temp = (temp*10) + root->right->val;
            sumNumbers(root->right);
            temp /= 10;
            // cout << "post - " << root->val << ", "<< temp << ", " << sum << endl; 
        }
        return sum;
    }
};

// Solution 2 : with helper funtion
class Solution {
public:
    int helper(TreeNode* root, int &temp, int &sum){
        if (!root) return 0;
        if (!root->left && !root->right){ 
            // cout << "leaf - " << root->val << ", "<< temp << ", " << sum << endl; 
            sum += temp;
            return root->val;
        }
        
        if (root->left) {
            // cout << "pre  - " << root->val << ", "<< temp << ", " << sum << endl; 
            temp = (temp*10) + root->left->val;
            helper(root->left, temp, sum);
            temp /= 10;
            // cout << "post - " << root->val << ", "<< temp << ", " << sum << endl; 
        }
        
        if (root->right) {
            // cout << "pre  - " << root->val << ", "<< temp << ", " << sum << endl; 
            temp = (temp*10) + root->right->val;
            helper(root->right, temp, sum);
            temp /= 10;
            // cout << "post - " << root->val << ", "<< temp << ", " << sum << endl; 
        }
        
        return sum;
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        int temp = root->val; 
        
        return helper(root, temp, sum);
    }
};

// Solution 3 : using member variable
class Solution {
    int sum = 0;
public:
    void helper(TreeNode* root, int temp){
        temp = (temp*10) + root->val;
        if (!root->left && !root->right){
            sum += temp;
            return;
        }        
        if (root->left) helper(root->left, temp);
        if (root->right) helper(root->right, temp);
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        helper(root, 0);
        return sum;
    }
};