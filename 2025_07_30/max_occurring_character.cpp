 
       #include <iostream>
#include <string>
using namespace std;

char getMaxOccCharacter(const string &s) {
    int arr[26] = {0};
    
    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z') {
            arr[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            arr[ch - 'A']++;
        }
    }

    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
            ans = i;
        }
    }

    char result = 'a' + ans;
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char maxChar = getMaxOccCharacter(s);
    cout << "Maximum occurring character: " << maxChar << endl;

    return 0;
}
