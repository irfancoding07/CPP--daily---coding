#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();

        int max_ones = 0;
        int max_ones_row = -1;

        for (int i = 0; i < n; i++) {
            // Find the first 1 using binary search (upper_bound)
            int curr_row_ones = m - (upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin());

            // Update max if current row has more 1s
            if (curr_row_ones > max_ones) {
                max_ones = curr_row_ones;
                max_ones_row = i;
            }
        }

        return max_ones_row;
    }
};

 int main() {
    vector<vector<int>> arr = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    Solution obj;
    int result = obj.rowWithMax1s(arr);

    if (result == -1)
        cout << "No 1s found in any row." << endl;
    else
        cout << "Row with maximum 1s: " << result << endl;

    return 0;
}
