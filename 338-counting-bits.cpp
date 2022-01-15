// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/

/*
Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:
0 <= n <= 105
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i <= n; i++){
            int once = 0;
            for (int b = 1; b < 32; b++){
                if ((i & (0x80000000 >> b))) once++;
            }
            vec.push_back(once);
        }
        return vec;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n + 1);
        vec[0] = 0;
		
        for (int i = 1; i <= n; i++){
            vec[i] = vec[i >> 1] + i % 2; // C(x) = C(x / 2) + x mod 2
        }
        return vec;
    }
};