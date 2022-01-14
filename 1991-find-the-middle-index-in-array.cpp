// 1991. Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array/

/*

Example 1:
Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4

Example 2:
Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0

Example 3:
Input: nums = [2,5]
Output: -1
Explanation: There is no valid middleIndex.
 
Constraints:
1 <= nums.length <= 100
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int right = 0, left = 0;
        
        for (int i : nums){
            right += i;
        }
        
        for (int i = 0; i < nums.size(); i++){
            right -= nums[i];
            if (right == left)
                return i;
            left += nums[i];
            
        }
        return -1;  
    }
};