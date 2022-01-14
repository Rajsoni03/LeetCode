// 66. Plus One
// https://leetcode.com/problems/plus-one/

/*
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/




class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator it = digits.rbegin();
        
        int sum = (*it) + 1;
        int carry = sum / 10;      
        sum = sum % 10;
        
        *it = sum;
        it++;
        
        while (it != digits.rend() && carry){
            sum = (*it) + carry;
            carry = sum / 10;    
            sum = sum % 10;
            *it = sum;
            it++;
        }    
        
        if (carry){
            vector<int> newVec;
            newVec.push_back(carry);
            for (auto i : digits){
                newVec.push_back(i);
            }
            return newVec;
        }
        return digits;      
    }
};