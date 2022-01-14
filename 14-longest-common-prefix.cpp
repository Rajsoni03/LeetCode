// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

/*
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/
class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0], s;

        for (int i = 1; i < strs.size(); i++){
            // cout << strs[i] << endl;
            s = "";

            for (int j = 0; j < lcp.size(); j++){
                if (lcp[j]==strs[i][j])
                    s.push_back(lcp[j]);
                else
                    break;
                // cout << "s - " << s << ",   lcp - " << lcp << endl;
            }
            lcp = s;
            if (lcp == ""){
                return "";
            }
        }
        return lcp;
    }   
};