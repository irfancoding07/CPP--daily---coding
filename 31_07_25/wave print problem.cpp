  #include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>> &arr, int rows, int cols) {
    for (int col = 0; col < cols; col++) {
        if (col % 2 == 0) {
            
            for (int row = 0; row < rows; row++) {
                cout << arr[row][col] << " ";
            }
        } else {
             
            for (int row = rows - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int rows = 3, cols = 3;
    vector<vector<int>> arr= {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    wavePrint(arr, rows, cols);

    return 0;
}
