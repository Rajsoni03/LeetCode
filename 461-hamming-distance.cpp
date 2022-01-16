// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/

/*

Example 1:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:
Input: x = 3, y = 1
Output: 1
 

Constraints:
0 <= x, y <= 231 - 1
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
//         1010
//         0011
//        ^____
//         1001
        
        int xr = x^y;
        int count = 0;
        for (int i = 1; i < 32; i++){
            if (xr & (0x80000000 >> i))
                count++;
        }
        return count;
        
    }
};