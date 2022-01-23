// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/

/*
Example 1:
Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Example 2:
Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.

Example 3:
Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
 
Constraints:
0 <= n < 109
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0) return 1;
        
        int newint = 0;
        bool val;
        bool flag = false;
        
        for (int i = 0; i < 32; i++){
            val = n & (0x80000000 >> i);
            if (val) flag=true;
            if (flag && !val){ 
                newint |= (0x80000000 >> i);
            }
        }
        return newint;
    }
};

// Code[Using bitmasking]:-
// class Solution {
// public:
//     int bitwiseComplement(int num) {
// 		    //base case
//         if(num == 0) return 1;
//         unsigned mask = ~0;
//         while( mask & num ) mask = mask << 1;
//         return ~num ^ mask;
//     }
// };
