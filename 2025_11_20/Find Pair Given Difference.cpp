#include<iostream>
using namespace std;

bool findPair(vector<int> &arr, int x) {
    int n = arr.size();
    
    // Sort the array.
    sort(arr.begin(), arr.end());
    
    int j = 1;
    
    for (int i = 0; i < n; i++) {
        
        // Move j forward while difference < x
        while (j < n && arr[j] - arr[i] < x)
            j++;
        
        // If difference is exactly x
        if (j < n && i != j && arr[j] - arr[i] == x)
            return true;
    }
    
    return false;
}

int main() {
    vector<int> arr = {5, 20, 3, 2, 50, 80};
    int x = 78;

    if (findPair(arr, x)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
 
