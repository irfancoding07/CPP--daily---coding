#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool areRotations(string &s1, string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        string con = s1 + s1;

        // Check if s2 exists inside s1+s1
        int index = con.find(s2);
        if (index == -1) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution obj;

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    if (obj.areRotations(s1, s2))
        cout << " Strings are rotations of each other.\n";
    else
        cout << " Strings are NOT rotations of each other.\n";

    return 0;
}
