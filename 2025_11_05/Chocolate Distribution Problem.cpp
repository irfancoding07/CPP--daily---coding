#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findMinDiff(vector<int> &arr, int m) {
   int n = a.size();
         
         sort(a.begin(),a.end());
         int mindiff = INT_MAX;
         
         for(int i =0; i + m -1 <n ; i++)
    {
     int diff = a[i + m -1] - a[i];
    
    if(diff < mindiff){
        mindiff = diff;
    }
}        
 
 return mindiff;
}
int main() {
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;
    cout << findMinDiff(arr, m);
    return 0;
}
