#include<iostream>
#include<vector>
using namespace std;

 
int minSwaps(vector<int>& arr) {
    int n = arr.size();

    // Store value along with its original index
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++){
        vec[i] = {arr[i], i};
    }

    
    sort(vec.begin(), vec.end());

    int swapp = 0;

    for(int i = 0; i < n; i++){
        // if element already in correct position
        if(vec[i].second == i)
            continue;
        else {
            swapp++;
            // swap with the position where vec[i] should go
            swap(vec[i], vec[vec[i].second]);
            // recheck same index again
            i--;
        }
    }
    return swapp;
}

int main() {
    
    vector<int> arr = {4, 3, 2, 1};

    
    int result = minSwaps(arr);

    cout << "Minimum swaps required = " << result << endl;

    return 0;
}
