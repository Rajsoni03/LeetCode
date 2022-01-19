// 1486. XOR Operation in an Array
// https://leetcode.com/problems/xor-operation-in-an-array/

/*
Example 1:
Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.

Example 2:
Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.
 

Constraints:

1 <= n <= 1000
0 <= start <= 1000
n == nums.length
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans ^= start+(i<<1);
        }
        return ans;
    }
};

// 0+2*0 =  0 = 00000000 -> 0
// 0+2*1 =  2 = 00000010 -> 2
// 0+2*2 =  4 = 00000100 -> 4
// 0+2*3 =  6 = 00000110 -> 0
// 0+2*4 =  8 = 00001000 -> 8
// 0+2*5 = 10 = 00001010 -> 2
// 0+2*6 = 12 = 00001100 -> 14
// 0+2*7 = 14 = 00001110 -> 0
// 0+2*8 = 16 = 00010000 -> 16
    


    
