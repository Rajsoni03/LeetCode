// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/

/*
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome. 

Constraints:
-231 <= x <= 231 - 1
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if ((x < 0) || (x%10 == 0 && x != 0))
            return false;
        else{
            long long int rev = 0;
            while (rev < x){
                rev = (rev*10) + (x % 10);
                x = x/10;
            }
            return (rev == x || rev/10 == x);
        }
        return false;
    }
    // bool isPalindrome(int x) {
    //     if (x < 0)
    //         return false;
    //     else{
    //         long long int rev = 0, temp = x;
    //         while (temp!=0){
    //             rev = (rev*10) + (temp % 10);
    //             temp = temp/10;
    //         } 
    //         // cout << rev << "--" << x <<'\n';
    //         if (rev == x){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};