// 1. Two Sum
// https://leetcode.com/problems/two-sum/

/*
example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;        
        int len = nums.size();
        
        for (int i=0; i<len; i++){
            int num = nums[i];
            int comp = target - num;
            if (mp.find(comp) == mp.end()){
                mp.insert({num, i});
            }
            else
                return vector<int>{i, mp[comp]};
        }
        return vector<int>{};
    }
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int len = nums.size();
    //     for (int i=0; i<len; i++){
    //         for (int j=i+1; j<len; j++){
    //             if ((nums[i] + nums[j]) == target){
    //                 return vector<int>{i, j};
    //             }
    //         }
    //     }
    //     return vector<int>{};
    // }
};
