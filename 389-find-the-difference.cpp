// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/
/*
Example 1:
Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.

Example 2:
Input: s = "", t = "y"
Output: "y"

Constraints:
0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.
*/


class Solution {
public:
    char findTheDifference(string s, string t) {
        int size = s.size();
        char ans = t[size];
        
        for (int i = 0; i < size; i++){
            ans = ans ^ (s[i] ^ t[i]);
        }
        return ans;
    }
};