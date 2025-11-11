#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int prev, next;

            //   Odd length palindrome  
            prev = i - 1;
            next = i + 1;
            while (prev >= 0 && next < n && s[prev] == s[next]) {
                prev--;
                next++;
            }
            if (next - prev - 1 > ans.size()) {
                ans = s.substr(prev + 1, next - prev - 1);
            }

            //   Even length palindrome  
            prev = i;
            next = i + 1;
            while (prev >= 0 && next < n && s[prev] == s[next]) {
                prev--;
                next++;
            }
            if (next - prev - 1 > ans.size()) {
                ans = s.substr(prev + 1, next - prev - 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    string result = sol.longestPalindrome(str);

    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
