// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/

/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
 
Example 1:
Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1

Example 3:
Input: s = "bb"
Output: 2
 

Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int arr[128]{};
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            if (islower(c)) arr[c] = arr[c] + 1;           
            else arr[c]++;
        }
        int count = 0;
        bool center = false;
        for (int i = 0; i < 128; i++){
            if (arr[i]==1 || arr[i] % 2==1){
                center = true;
            }
            if (arr[i]>1){
                count += (arr[i]/2) * 2;
            }
        }
        if (center){ count++;}
        
        return count;
    }
};


