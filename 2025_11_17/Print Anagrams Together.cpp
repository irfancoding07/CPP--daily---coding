#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < arr.size(); i++) {
            string temp = arr[i];
            sort(temp.begin(), temp.end());   // sorted key
            mp[temp].push_back(arr[i]);
        }

        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<vector<string>> result = obj.anagrams(arr);

    cout << "\nGrouped Anagrams:\n";
    for (auto &group : result) {
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
