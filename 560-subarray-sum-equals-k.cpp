// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

/*
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            auto it = mp.find(sum-k);
            if (it != mp.end())
                count+= it->second;
            
            if (mp.find(sum) == mp.end())
                mp[sum] = 1;
            else 
                mp[sum] = mp[sum] + 1;
        }
        return count;
        
        
//         int len = nums.size();
//         int sum = 0, count = 0;
        
//         for (int i = 0; i < len; i++){
//             sum = 0;
//             for (int j = i; j < len; j++){
//                 sum += nums[j];
//                 if (sum == k)
//                     count++;
//             }
//         }//         return count;//         return count;
        // return count;
        
        
//         if (k == 0)
//             return 0;
//         int start=0, end=0;
//         int len = nums.size();
//         int sum = 0;
//         int count = 0;
//         while(end < len){
//             while(sum < k){
//                 sum += nums[start];
//                 start++;
//                 cout << "1 - " ;
//             }
//             while(sum > k){
//                 sum -= nums[end];
//                 end++;
//                 cout << "2 - " ;
//             }
//             if (sum == k){
//                 count++;
//                 if (start < len)
//                     start++;
//                 else 
//                     end++;
//                 cout << "3 - " ;
//             }
//             cout  << end << ", "<< start  << ", " << sum <<"\n";
            
//         }
        
//         while(true){            
//             if (sum < k){
//                 if (start == len)
//                     break;
//                 sum += nums[start];
//                 start++;
//                 cout << "1 - " ;
//                 cout << start << ", " << end << ", " << sum <<"\n";
//             }
//             else if (sum > k){
//                 if (end == len)
//                     break;
//                 if (start <= end)
//                     start++;
//                 else
//                     sum -= nums[end];
//                 end++;
//                 cout << "2 - " ;
//                 cout << start << ", " << end << ", " << sum <<"\n";
//             }
            
//             if (sum == k){                
//                 if (end == len)
//                     break;
//                 sum -= nums[end];
//                 count++;
//                 end++;
//                 if (start < end)
//                     start++;
//                 cout << "3 - " ;
//                 cout << start << ", " << end << ", " << sum <<"\n";
//             }
//         }
//        return count;
        
    }
};