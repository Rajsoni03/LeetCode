// 190. Reverse Bits
// https://leetcode.com/problems/reverse-bits/

/*
Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

Constraints:
The input must be a binary string of length 32
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0;
        uint32_t temp = n;
        for (int i = 0; i < 31; i++){
            temp = n >> i;
            re |= (temp & 0x00000001);
            re <<= 1;
        }
        re |= ((n>>31) & 0x00000001);
        return re;
    }
};