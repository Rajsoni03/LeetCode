// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

/*
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int i = 0, j = nums.size();

        while (i<j){
            int mid = (i+j) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]){ j = mid; }
            else { i = mid + 1; }
        }
        return j;
    }
};