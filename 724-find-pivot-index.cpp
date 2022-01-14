// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
/*


Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

Constraints:
1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
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