#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Question 1
int main(){
	string s = "lEeTcOdE";

	vector<int> arr(26, 0);
	char t = '1';
    for (int i = 0; i < s.size(); i++){
    	t=s[i];
        if (islower(t)){
        	if (arr[t-'a'] == 0) arr[t-'a'] = -1;
            else if (arr[t-'a'] == 1) arr[t-'a'] = 2;
        } 
        else if (isupper(t)){
        	if (arr[t-'A'] == 0) arr[t-'A'] = 1;
            else if (arr[t-'A'] == -1) arr[t-'A'] = 2;
        } 
    }
    string c = "";
    for (int i = 25; i >= 0; i--){
        if (arr[i] == 2) { 
            c = char(i+'A');
            break;
        }            
    }
    cout << c << endl;
	return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <climits>
// using namespace std;


// int main(){
// 	int num = 47;
// 	int k = 9;

// 	int t = INT_MAX;
// 	int count = 0;
// 	for (int i = 0; t > i+k; i+=10){
// 		t = num - i-k;
// 		if (t <= i+k) break;
// 		if (t%10 == k){
// 			count++;
// 		}
// 		cout << t <<'\t' << i+k << endl;
// 	}



//     cout << count << endl;
// 	return 0;
// }