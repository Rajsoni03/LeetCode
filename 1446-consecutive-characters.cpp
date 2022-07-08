// 1446. Consecutive Characters
// https://leetcode.com/problems/consecutive-characters/

/*
Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters.
*/

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int ans = 0;
        char last = s[0];
        int temp = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == last){
                temp++;
            }
            else {
                last = s[i];
                temp = 0;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};


/*
class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        vector<int> arr(26, 0);
        vector<int> temp(26, 0);
        
        char last = s[0];
        temp[last-'a'] = 1;
        arr[last-'a'] = 1;
        
        int count = 0;
        for (int i = 1; i < n; i++){
            if (s[i] == last) temp[last-'a']++;
            else{
                temp[last-'a'] = 0;
                last=s[i];
                i--;
            }
            arr[s[i]-'a'] = max(arr[s[i]-'a'], temp[s[i]-'a']);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++){
            ans = max(ans, arr[i]);
            // cout << arr[i] << ' ';
        }
        // cout << endl;
        return ans;
    }
};
*/