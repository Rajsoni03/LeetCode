// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

/*
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false


Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {

        if (s.size() == 0) return true;
        if (s.size() == 1) return false;

        stack<char> stk{};
        for (int i = 0; i< s.size(); i++){
            char c = s[i];
            if (stk.empty()){
                stk.push(c);
            }
            else if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.top() != '{' && c == '}') return false;
                if (stk.top() != '[' && c == ']') return false;
                if (stk.top() != '(' && c == ')') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};