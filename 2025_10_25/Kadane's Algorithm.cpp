#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    
    // Stores the result (maximum sum found so far)
    int res = arr[0];           
    
    // Maximum sum of subarray ending at current position
    int maxEnding = arr[0];     

    for (int i = 1; i < arr.size(); i++) {
        
        // Either extend the previous subarray or start 
        // new from current element
        maxEnding = max(arr[i], maxEnding + arr[i]);

        // Update result if the new subarray sum is larger
        res = max(res, maxEnding);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr); 
    return 0;
}
