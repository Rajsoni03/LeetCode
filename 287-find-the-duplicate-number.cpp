// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

/*
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
 
Constraints:
1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_set<int> st;        
//         int n = nums.size();        
//         for (int i = 0; i < n; i++){
//             if (st.find(nums[i])!=st.end()) return nums[i];
//             st.insert(nums[i]);
//         }        
//         return nums[n-1];
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {        
        int fast = nums[nums[nums[0]]];
        int slow = nums[nums[0]];
        
        while(fast!=slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        
        slow = nums[0];
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return fast;
    }
};

//           <
// 1 > 3 > 2 > 4
//         ^   
//         ^
