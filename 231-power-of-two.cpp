// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

/*
Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        signed short int once = 0;
        for (int i = 1; i < 32; i++){
            if (n & (0x80000000 >> i)) once++;
            if (once > 1) return false;
        }
        return true;
    }
};