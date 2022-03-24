// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

/*
Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:
0 <= n <= 30
*/

class Solution {
public:
    int fib(int n) {
        // Solution - 2 (DP)
        if (n <= 1) return n;
        
        int prev = 0, curr = 1;
        int sum;
        while(n-- > 1){
            sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;      
        
        // Solution - 1 (recursion)
        // if (n <= 0) return 0;
        // else if (n == 1) return 1;
        // return fib(n-1) + fib(n-2);
    }
};