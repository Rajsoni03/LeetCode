// 989. Add to Array-Form of Integer
// https://leetcode.com/problems/add-to-array-form-of-integer/

/*
Example 1:
Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:
Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:
Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 

Constraints:
1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {        
        int num_len = num.size();        
        if (num_len == 0) return num;
        
        vector<int> v(num_len);
        
        int sum = 0;
        int carry = 0;
        
        while(num_len){
            --num_len;
            sum = num[num_len] + (k%10) + carry;
            carry = sum / 10;
            sum = sum % 10;
            k = k/10;
            v[num_len] = sum;
        }
        while(k){
            sum = (k % 10) + carry;
            carry = sum / 10;
            sum = sum % 10;
            k = k/10;
            v.insert(v.begin(), sum);
        }
        if (carry){
            v.insert(v.begin(), carry);
        }
        return v;
        
    }
};