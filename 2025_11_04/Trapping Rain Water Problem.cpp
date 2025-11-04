#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        int l = 0;
        int r = n - 1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            lmax = max(lmax, arr[l]);
            rmax = max(rmax, arr[r]);

            if (lmax < rmax) {
                ans += lmax - arr[l];
                l++;
            } else {
                ans += rmax - arr[r];
                r--;
            }
        }
        return ans;
    }
};

 
int main() {
    Solution obj;

    vector<int> arr = {3, 0, 2, 0, 4};

    int result = obj.maxWater(arr);

    cout << "Maximum water trapped = " << result << endl;

    return 0;
}
