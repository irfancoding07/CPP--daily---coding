     #include <iostream>
using namespace std;

bool isPresent(int arr[][3], int target) {
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(arr[row][col] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[3][3];

    cout << "Enter 9 elements for 3x3 matrix:" << endl;
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }

    cout << "Enter element to search: ";
    int target;
    cin >> target;

    if(isPresent(arr, target)) {
        cout << "Element found" << endl;  
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
