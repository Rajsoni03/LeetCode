// 204. Count Primes
// https://leetcode.com/problems/count-primes/

/*
Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
 

Constraints:
0 <= n <= 5 * 106

*/

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> arr(n, true);
        int i = 2;
        for (int sq = sqrt(n); i <= sq; i++){
            if (arr[i]){
                count++;
                for (int j = i*2; j < n; j+=i) arr[j] = false;
            } 
        }
        for (; i < n; i++){
            if (arr[i]) count++;
        }
        return count;
    }
};
