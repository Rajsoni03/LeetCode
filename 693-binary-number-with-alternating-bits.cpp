// 693. Binary Number with Alternating Bits
// https://leetcode.com/problems/binary-number-with-alternating-bits/

/*
Example 1:
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
 

Constraints:
1 <= n <= 231 - 1

*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans = false;
        bool flag = false;
        for (int i = 1; i < 32; i++){
            if (n & (0x80000000 >> i)) flag = true;
            if (flag == true)   {
                bool bit = (n & (0x80000000 >> i));
                // cout << ans << " - "<< bit << endl;
                if (ans != bit)
                    ans = bit;
                else 
                    return false;
            }
        }           
        
        return true;
    }
};