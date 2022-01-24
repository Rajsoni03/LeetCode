// 1299. Replace Elements with Greatest Element on Right Side
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

/*
Example 1:
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.

Example 2:
Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
 
Constraints:
1 <= arr.length <= 104
1 <= arr[i] <= 105
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        int max = -1;
        int pos = 0;
        bool flag = true;
        
        for (int i = 0; i < n-1; i++){
            if (pos <= i){
                max = -1;
                for (int j = i+1; j < n; j++){
                    if (max < arr[j]){
                        max = arr[j];
                        pos = j;
                    }   
                    // cout << arr[i] << " - " << arr[j] << " - "<< pos << " - " << max << endl;
                }
            }
            arr[i] = max;
        }
        arr[n-1] = -1;
        return arr;
    }
};

// pos = 1;
// [17,18,5,4,6,1]
//            ^


