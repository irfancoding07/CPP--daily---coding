#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();

        int count = 0;
        int total = row * col;

        int startingRow = 0;
        int endingRow = row - 1;
        int startingCol = 0;
        int endingCol = col - 1;

        vector<int> ans;

        while (count < total) {
            
            // Print startingrow (→)
            for (int i = startingCol; count < total && i <= endingCol; i++) {
                ans.push_back(mat[startingRow][i]);
                count++;
            }
            startingRow++;

            // Print endingcol (↓)
            for (int i = startingRow; count < total && i <= endingRow; i++) {
                ans.push_back(mat[i][endingCol]);
                count++;
            }
            endingCol--;

            // Print endingrow (←)
            for (int i = endingCol; count < total && i >= startingCol; i--) {
                ans.push_back(mat[endingRow][i]);
                count++;
            }
            endingRow--;

            // Print startingcol (↑)
            for (int i = endingRow; count < total && i >= startingRow; i--) {
                ans.push_back(mat[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};

 

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = obj.spirallyTraverse(mat);

    cout << "Spiral Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
