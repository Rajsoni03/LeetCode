// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1] 

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return {-1, -1};
        
        int first_pos = -1;
        int last_pos = -1;
        
        int start = 0;
        int end = n-1;
        int mid;
        
        while(start<=end){
            mid = start + (end-start)/2;
            if (nums[mid]==target){
                first_pos = mid;
                end = mid-1;
            }
            else if (nums[mid]>target) end = mid-1;
            else start = mid+1;                
        }
        
        start = 0;
        end = n-1;
        while(start<=end){
            mid = start + (end-start)/2;
            if (nums[mid]==target){
                last_pos = mid;
                start = mid+1;  
            }
            else if (nums[mid]>target) end = mid-1;
            else start = mid+1;                
        }
        
        return {first_pos, last_pos};
    }
};