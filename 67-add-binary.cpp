// 67. Add Binary
// https://leetcode.com/problems/add-binary/

/*
Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/


class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        
        string::reverse_iterator it1 = a.rbegin();
        string::reverse_iterator it2 = b.rbegin();
        
        int sum = (*it1) + (*it2) - '0' - '0';
        int carry = sum / 2;
        sum = sum % 2;
        cout << sum << " - " << carry << endl;
        
        s = (char)(sum + '0') + s;
        
        it1++; it2++;
        while(it1 != a.rend() && it2 != b.rend()){
            sum = (*it1) + (*it2) + carry - '0' - '0';
            carry = sum / 2;
            sum = sum % 2;       
            s = (char)(sum + '0') + s;
            it1++; it2++;
        }
        while(it1 != a.rend()){
            sum = (*it1) - '0' + carry;
            carry = sum / 2;
            sum = sum % 2;            
            s = (char)(sum + '0') + s;
            it1++;
        }
        while(it2 != b.rend()){
            sum = (*it2) - '0' + carry;
            carry = sum / 2;
            sum = sum % 2;   
            s = (char)(sum + '0') + s;
            it2++;
        }
        if (carry){
            s = '1' + s;
        }
        return s;
    }
};