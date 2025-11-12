#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans) {
    // Base case: when index reaches end of string
    if (index >= str.length()) {
        ans.push_back(output);
        return;
    }

    // Exclude current character
    solve(str, output, index + 1, ans);

    // Include current character
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";   
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    vector<string> result = subsequences(str);

    cout << "\nAll subsequences are:\n";
    for (auto s : result) {
        if (s.empty())
            cout << "\"\" (empty)" << endl;
        else
            cout << s << endl;
    }

    return 0;
}
