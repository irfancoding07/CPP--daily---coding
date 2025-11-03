#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &arr) {
    unordered_set<int> st;
    int res = 0;

    // Step 1 Insert all elements into a set
    for (int val : arr)
        st.insert(val);

    // Step 2 Check for the start of each sequence
    for (int val : arr) {
        // If val-1 not found, val is the start of a new sequence
        if (st.find(val) != st.end() && st.find(val - 1) == st.end()) {
            int cur = val, cnt = 0;

            // Count all consecutive elements
            while (st.find(cur) != st.end()) {
                st.erase(cur); // remove to avoid rechecking
                cur++;
                cnt++;
            }

            // Update result
            res = max(res, cnt);
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};

    cout << "Longest consecutive subsequence length: "
         << longestConsecutive(arr) << endl;

    return 0;
}
