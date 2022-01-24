// 1929. Concatenation of Array
// https://leetcode.com/problems/concatenation-of-array/

/*
Example 1:
Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]

- Example 2:
Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:
n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n*2);
        
        for (int i = 0; i < n; i++){
            ans[i] = nums[i];
            ans[n+i] = nums[i];
        }
        return ans;
    }
};