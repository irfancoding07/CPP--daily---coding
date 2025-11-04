#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     
    bool isSubset(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int m = a.size(), n = b.size();

        while (i < m && j < n) {
            if (a[i] < b[j]) {
                i++;   
            }
            else if (a[i] == b[j]) {
                i++;
                j++;   
            }
            else {
                // a[i] > b[j] → means b[j] not found in a
                return false;
            }
        }

        // If all elements of b were found in a, j will reach n
        return (j == n);
    }
};

 

int main() {
    Solution obj;

   
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};

    if (obj.isSubset(a, b))
        cout << "Yes, b is a subset of a" << endl;
    else
        cout << "No, b is NOT a subset of a" << endl;

    
    vector<int> a2 = {10, 5, 2, 23, 19};
    vector<int> b2 = {19, 5, 3};

    if (obj.isSubset(a2, b2))
        cout << "Yes, b2 is a subset of a2" << endl;
    else
        cout << "No, b2 is NOT a subset of a2" << endl;

    return 0;
}
