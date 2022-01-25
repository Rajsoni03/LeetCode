// 868. Binary Gap
// https://leetcode.com/problems/binary-gap/

/*
Example 1:

Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
Example 2:

Input: n = 8
Output: 0
Explanation: 8 in binary is "1000".
There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.
Example 3:

Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
 

Constraints:

1 <= n <= 109
*/

class Solution {
public:
    int binaryGap(int n) {
        int fast = 0;
        int slow = 0;
        int max = 0;
        bool bit;

        while (fast < 32){
            bit = n & (0x80000000 >> fast);
            if (bit){
                slow = fast;
                break;
            }
            fast++;
        }
        while (fast < 32){
            bit = n & (0x80000000 >> fast);
            if (bit) {
                if (max < (fast-slow)) max = fast-slow;
                slow = fast;
            }
            fast++;
        }
        return max;
    }
};
