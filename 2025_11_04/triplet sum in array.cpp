#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Step 1: Sort the array

        for (int i = 0; i < n - 2; i++) { // Step 2: Fix one element
            int left = i + 1, right = n - 1;

            while (left < right) { // Step 3: Use two-pointer technique
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == target) {
                    return true; // Triplet found
                }
                else if (sum < target) {
                    left++;  
                }
                else {
                    right--;  
                }
            }
        }
        return false; // No triplet found
    }
};

int main() {
    Solution obj;
    vector<int> arr = {12, 3, 4, 1, 6, 9};
    int target = 24;

    if (obj.hasTripletSum(arr, target))
        cout << "Triplet with sum " << target << " exists.\n";
    else
        cout << "No triplet with sum " << target << " found.\n";

    return 0;
}
