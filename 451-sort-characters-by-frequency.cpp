// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters. 

Constraints:
1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int freq[128]{};
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            freq[c] = freq[c]+1;
        }        
        
        vector<pair<int, char>> pairs;
        for (int i = 0; i < 128; i++){
            if (freq[i]>0) pairs.push_back({freq[i], i});          
        }        
        
        sort(pairs.begin(), pairs.end());       
        
        string ans;
        for (auto i : pairs){
            ans = string(i.first, i.second) + ans;
            // cout << i.first << " - " << i.second << endl;
        }
        
        return ans;
    }
};

int main(){
    string s = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz0011223344556677889";
    Solution sol;    
    cout << sol.frequencySort(s);
    
    return 0;
}