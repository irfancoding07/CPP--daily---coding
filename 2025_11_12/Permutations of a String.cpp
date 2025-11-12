#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    set<string> st;

    void recursiveFunc(int i, string s) {
        int n = s.size();

        // base case
        if (i == n) {
            st.insert(s);
            return;
        }

        // generate all permutations
        for (int j = i; j < n; j++) {
            swap(s[i], s[j]);
            recursiveFunc(i + 1, s);
            swap(s[i], s[j]); // backtrack
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> ans;
        recursiveFunc(0, s);

        for (auto &it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};

 
int main() {
    Solution obj;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result = obj.findPermutation(s);

    cout << "\nAll unique permutations:\n";
    for (auto &str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
