// 1089. Duplicate Zeros
// https://leetcode.com/problems/duplicate-zeros/

/*
Example 1:
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]


Example 2:
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Constraints:
1 <= arr.length <= 104
0 <= arr[i] <= 9
*/


// n = 8
// 0, 1, 2, 3, 4, 5, 6, 7

// 1, 0, 0, 2, 3, 0, 0, 4
// ^ 
//       ^

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
            
        for (int i = n-1; i >= 0; i--){
            if (arr[i]==0){
                for (int j = n-1; j > i; j--){
                    arr[j] = arr[j-1];
                }
            }
        }
    }
};
