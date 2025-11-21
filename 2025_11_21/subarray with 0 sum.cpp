#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int findSubarray(vector<int> &arr) {
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Case 1: If sum becomes zero
        if (sum == 0)
            ans++;

        // Case 2: If same prefix sum seen before
        if (mp.find(sum) != mp.end())
            ans += mp[sum];

        // Increase frequency of this prefix sum
        mp[sum]++;
    }
    return ans;
}

int main() {
    vector<int> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};

    int result = findSubarray(arr);

    cout << "Total Zero Sum Subarrays = " << result << endl;

    return 0;
}
