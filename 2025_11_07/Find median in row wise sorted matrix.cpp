#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  // ✅ Function to count how many elements in a row are <= mid
  int countSmallerEqual(vector<int> &row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
  }

  int median(vector<vector<int>> &mat) {
   int r = mat.size();         
    int c = mat[0].size();      

    int low = INT_MAX, high = INT_MIN;

    //  find global minimum and maximum in matrix
    for (int i = 0; i < r; i++) {
        low = min(low, mat[i][0]);         
        high = max(high, mat[i][c - 1]);  
    }

    int desired = (r * c + 1) / 2;  // position of median element in sorted order

    // binary search on the range of possible values
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        //  Count how many elements ≤ mid in all rows
        for (int i = 0; i < r; i++) {
            count += countSmallerEqual(mat[i], mid);
        }

        //  Adjust search range based on count
        if (count < desired)
            low = mid + 1;  // too few numbers ≤ mid → median is larger
        else
            high = mid;    //count >= desired
    }

 
    return low;
  }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median is: " << sol.median(mat) << endl;
    return 0;
}
