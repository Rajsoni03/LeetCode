// 415. Add Strings
// https://leetcode.com/problems/add-strings/

/*
Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string s = "";
        
        string::reverse_iterator  n1 = num1.rbegin();
        string::reverse_iterator  n2 = num2.rbegin();
        
        int carry = 0;
        int sum = 0;
        
        while (n1 != num1.rend() && n2 != num2.rend()){
            sum = (*n1) - '0' + (*n2) - '0' + carry;
            carry = sum / 10;
            sum = (sum % 10) + '0';
            s = (char)sum + s;
            n1++; 
            n2++;
        }
        while (n1 != num1.rend()){
            sum = (*n1) - '0' + carry;
            carry = sum / 10;
            sum = (sum % 10) + '0';
            s = (char)sum + s;
            n1++; 
        }
        while (n2 != num2.rend()){
            sum = (*n2) - '0' + carry;
            carry = sum / 10;
            sum = (sum % 10) + '0';
            s = (char)sum + s;
            n2++;
        }
        if (carry){
            s = "1" + s;
        }
               
        return s;
    }
};