#include <iostream>
using namespace std;

class Solution {
public:

    int firstOccurrences(vector<int>& arr, int x, int n){
        int s = 0, e = n - 1;
        int ans = -1;

        while (s <= e){
            int mid = s + (e - s) / 2;

            if(arr[mid] == x){
                ans = mid;
                e = mid - 1;
            }
            else if(x > arr[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurrences(vector<int>& arr, int x, int n){
        int s = 0, e = n - 1;
        int ans = -1;

        while (s <= e){
            int mid = s + (e - s) / 2;

            if(arr[mid] == x){
                ans = mid;
                s = mid + 1;
            }
            else if(x > arr[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }

    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();

        int first = firstOccurrences(arr, x, n);
        int last  = lastOccurrences(arr, x, n);

        return {first, last};
    }
};

int main() {
    Solution obj;

    int n, x;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    vector<int> ans = obj.find(arr, x);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
