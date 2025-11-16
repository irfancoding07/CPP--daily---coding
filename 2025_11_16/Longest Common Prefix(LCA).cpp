#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
          int n = strs.size();
        for(int i=0; i<strs[0].length();i++){
            char ch = strs[0][i];

            bool match = true;

            //for comparing ch with rest of the string 
            for(int j=1; j<n;j++){
                ///not match
                if(strs[j].size() < i || ch != strs[j][i]){
                    match =  false ;
                    break;
                }
            }
            if(match == false ){
                break;
            }
            else {
                ans.push_back(ch);
            }
            
        }
        return ans;
    }
};

int main() {

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;
    string result = obj.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
