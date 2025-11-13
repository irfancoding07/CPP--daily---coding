#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isBalanced(string &s) {
         stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

             
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                
                if (!st.empty()) {
                    char top = st.top();

                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                        st.pop();
                    }
                    else { //Matching, but wrong type
                        return false;
                    }
                }
                else { //Nothing to match with
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a bracket string: ";
    cin >> s;

    if (obj.isBalanced(s)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}
