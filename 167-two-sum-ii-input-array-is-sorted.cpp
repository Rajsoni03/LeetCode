// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/*
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int size = numbers.size();
        
        for (int i = 0; i < size-1; i++){
            int searchFor = target - numbers[i];
            
            int start = i+1;
            int end = size-1;                
            int mid = (start+end)/2;
            
            while(start<=end){
                mid = (start+end)/2;
                
                if (searchFor == numbers[mid]){
                    return {i+1, mid+1};
                }
                else if (searchFor < numbers[mid]){
                    end = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
        }
        return {1,2};
    }
};