#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    int mergecount(vector<int>& arr, int st, int mid, int end) {
        vector<int> temp;
        int i = st;
        int j = mid + 1;
        int invcount = 0;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                invcount += (mid - i + 1); // count inversions
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= end)
            temp.push_back(arr[j++]);

        // copy merged array back
        for (int idx = 0; idx < temp.size(); idx++) {
            arr[st + idx] = temp[idx];
        }

        return invcount;
    }

    // Recursive merge sort that counts inversions
    int mergesort(vector<int>& arr, int st, int end) {
        int invcount = 0;
        if (st < end) {
            int mid = (st + end) / 2;
            invcount += mergesort(arr, st, mid);         // left half
            invcount += mergesort(arr, mid + 1, end);    // right half
            invcount += mergecount(arr, st, mid, end);   // merge step
        }
        return invcount;
    }

    // Main inversion count function
    int inversionCount(vector<int>& arr) {
        return mergesort(arr, 0, arr.size() - 1);
    }
};

 
int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    
    Solution obj;
    int ans = obj.inversionCount(arr);
    
    cout << "Total inversion count: " << ans << endl;
    
    return 0;
}
