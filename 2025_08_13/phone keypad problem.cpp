  #include <iostream>
using namespace std;

string keypadMap[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void generateCombinations(string digits, int index, string output) {
 
    if (index == digits.length()) {
        cout << output << endl;
        return;
    }

    int digit = digits[index] - '0';  
    string letters = keypadMap[digit];

    for (char ch : letters) {
        generateCombinations(digits, index + 1, output + ch);
    }
}

int main() {
    string digits;
    cout << "Enter digits (2-9)" << " " ;
    cin >> digits;

    if (digits.empty()) {
        cout << "No digits entered!" << endl;
        return 0;
    }

    cout << "Possible combinations" << endl;
    generateCombinations(digits, 0, "");
    return 0;
}
