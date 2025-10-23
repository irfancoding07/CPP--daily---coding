#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Minimum element: " << minVal << endl;
    cout << "Maximum element: " << maxVal << endl;

    return 0;
}
