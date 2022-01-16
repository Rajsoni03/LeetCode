// 477. Total Hamming Distance
// https://leetcode.com/problems/total-hamming-distance/


/*
Example 1:
Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Example 2:
Input: nums = [4,14,4]
Output: 4
 

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 109
The answer for the given input will fit in a 32-bit integer.
*/


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int totalCount = 0;
        int size = nums.size();  
        
        for (int bit = 1; bit < 32; bit++){
            int count = 0;
            for (int i = 0; i < size; i++){       
                bool b = (nums[i]&(0x80000000>>bit));
                count += b;
                // cout << count << " - " << b << ", ";
            }                
            totalCount += count * (size - count);
            
            // cout << "  - "<< totalCount << endl;
        }
        
        return totalCount;
    }
};

