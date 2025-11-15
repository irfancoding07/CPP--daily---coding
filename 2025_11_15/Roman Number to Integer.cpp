#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> val;
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;

    int n = s.length();
    int total = 0;

    for (int i = 0; i < n; i++) {
        // If current value is less than next → subtract
        if (i + 1 < n && val[s[i]] < val[s[i + 1]]) {
            total -= val[s[i]];
        }
        else { 
            total += val[s[i]];
        }
    }

    return total;
}

int main() {
    string s;
    cout << "Enter Roman Number: ";
    cin >> s;

    cout << "Integer Value = " << romanToInt(s);
    return 0;
}
