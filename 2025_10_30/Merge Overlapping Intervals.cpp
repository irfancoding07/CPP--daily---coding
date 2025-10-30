#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort the intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        // Step 2: Traverse each interval
        for (auto interval : intervals) {
            // If merged list is empty or no overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlapping intervals → merge them
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

int main() {
    Solution obj;

    // Input intervals
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    // Call function
    vector<vector<int>> result = obj.merge(intervals);

    // Print output
    cout << "Merged Intervals: ";
    for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    return 0;
}
