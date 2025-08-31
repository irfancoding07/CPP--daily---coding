  #include <iostream>
 #include <climits>
using namespace std;

void printRowSum(int arr[][3], int rows, int cols) {
    cout << "Row-wise sums: ";
    for(int row = 0; row < rows; row++) {
        int sum = 0;
        for(int col = 0; col < cols; col++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void printColSum(int arr[][3], int rows, int cols) {
    cout << "Column-wise sums: ";
    for(int col = 0; col < cols; col++) {
        int sum = 0;
        for(int row = 0; row < rows; row++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void largestRowSum(int arr[][3], int rows, int cols) {
    int maxi = INT_MIN;
    int rowIndex = 0;
    for(int row = 0; row < rows; row++) {
        int sum = 0;
        for(int col = 0; col < cols; col++) {
            sum += arr[row][col];
        }
        if(sum > maxi) {
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << "Largest row sum is " << maxi << " at row index " << rowIndex << endl;
}

void largestColSum(int arr[][3], int rows, int cols) {
    int maxi = INT_MIN;
    int colIndex = -1;
    for(int col = 0; col < cols; col++) {
        int sum = 0;
        for(int row = 0; row < rows; row++) {
            sum += arr[row][col];
        }
        if(sum > maxi) {
            maxi = sum;
            colIndex = col;
        }
    }
    cout << "Largest column sum is " << maxi << " at column index " << colIndex << endl;
}

int main() {
    int arr[3][3];
    cout << "Enter 9 elements for 3x3 matrix:" << endl;
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            cin >> arr[row][col];
        }
    }

    printRowSum(arr, 3, 3);
    printColSum(arr, 3, 3);

    largestRowSum(arr, 3, 3);
    largestColSum(arr, 3, 3);

    return 0;
}
