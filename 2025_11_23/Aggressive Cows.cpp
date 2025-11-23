
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
  
  bool isPossible(vector<int> &stalls, int k, int mid) {
      int cowCount = 1;                 // place 1st cow in first stall
      int lastPos = stalls[0];

      for (int i = 1; i < stalls.size(); i++) {
          if (stalls[i] - lastPos >= mid) {
              cowCount++;
              lastPos = stalls[i];
              if (cowCount == k) {
                  return true;         // all cows placed successfully
              }
          }
      }
      return false;
  }

 int aggressiveCows(vector<int> &stalls, int k) {
      sort(stalls.begin(), stalls.end());

      int s = 1;
      int maxi = stalls[stalls.size() - 1];
      int e = maxi;
      int ans = -1;

      while (s <= e) {
          int mid = s + (e - s) / 2;
          if (isPossible(stalls, k, mid)) {
              ans = mid;
              s = mid + 1;              
          }
          else {
              e = mid - 1;               
          }
      }
      return ans;
  }
};


int main() {
    int n, k;
    cin >> n >> k;                 

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];                
    }

    Solution obj;
    cout << obj.aggressiveCows(stalls, k) << endl;
    return 0;
}
