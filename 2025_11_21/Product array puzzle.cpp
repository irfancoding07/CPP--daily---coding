#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
        
    vector<int> ans(n);   //  allocate size
    
    int left = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = left;
        left = left * arr[i];
    }
        
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= right;
        right = right * arr[i];
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    vector<int> result = productExceptSelf(arr);

    cout << "Product Except Self: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
