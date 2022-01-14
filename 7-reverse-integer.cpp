// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

/*
Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 

Constraints:
-231 <= x <= 231 - 1
*/

class Solution {
    public:
        int reverse(int x) {
            long int temp, i;
            long int result=0;

            i = abs(x);
            while (i != 0){
                temp = i % 10;
                i = i / 10;
                result = (result * 10) + temp;
                if (result > INT_MAX)
                    return 0;
            }
            if (x<0)
                return -result;

            return result;
        }
};