// 1720. Decode XORed Array
// https://leetcode.com/problems/decode-xored-array/

/*
Example 1:
Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]

Example 2:
Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]
 

Constraints:

2 <= n <= 104
encoded.length == n - 1
0 <= encoded[i] <= 105
0 <= first <= 105
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size();
        vector<int> vec(size+1);
        vec[0] = first;
        for (int i = 0; i < size; i++){
            vec[i+1] = encoded[i] ^ vec[i];
        }
        return vec;
    }
};