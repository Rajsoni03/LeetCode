// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
//         int len=0, temp_len = 0;
//         unordered_map<char, int> hash;

//         for (int i = 0; i < s.size(); i++){
//             if (hash.find(s[i]) == hash.end()){
//                 hash[(s[i])] = i;
//                 temp_len++;
//                 if (temp_len > len)
//                     len = temp_len;
//             }            
//             else{
//                 i = hash[(s[i])]+1;
//                 hash.clear();
//                 hash[(s[i])] = i;
//                 temp_len = 1;
//             }
//         }
//        return len;
//    }
    int lengthOfLongestSubstring(string s) {
        int len=0, temp_len = 0;
        unordered_map<int, int> hash;

        for (int i = 0; i < s.size(); i++){
            if (hash.find(s[i]) != hash.end()){
                temp_len = max (temp_len, hash[s[i]]+1);
            }    
            len = max(len, i+1-temp_len);
            hash[s[i]] = i;

        }
        return len;
    }

};