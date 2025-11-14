#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int getLPSLength(string &s) {
     int n = s.length();
        int prefix = 0;
        int suffix = 1;
        int position = 1;
        int count = 0;
        
        while(prefix < n && suffix<n){
            if(s[prefix] == s[suffix]){
                prefix++;
                suffix++;
                count++;
            }
            else { //(p!=s)
                prefix=0;
                position++;
                suffix = position;
                count = 0;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int answer = obj.getLPSLength(s);
    cout << "LPS Length = " << answer << endl;

    return 0;
}
