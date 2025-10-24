#include <iostream>
#include <vector>
using namespace std;

 vector<int> move(vector<int> &arr) {
    int left = 0, right = arr.size()-1;
    while (left<right) {
        
        // increment left while arr[left]
        // is negative
        while (left<right && arr[left]<0) {
            left++;
        }
        
        // decrement right while arr[right]
        // is positive
        while (right>left && arr[right]>0) {
            right--;
        }
        
        // swap the two values.
        if (right>left) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    
    return arr;
}

int main() {
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);
    
    for (auto num: ans) {
        cout << num << " ";
    }
    cout<<endl;

    return 0;
}
