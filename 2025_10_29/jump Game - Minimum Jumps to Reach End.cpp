#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int> &arr) {
    int n = arr.size();

    // If array has only one element, we are already at the end
    if (n <= 1) return 0;

    // If the first element is 0, we can’t move anywhere
    if (arr[0] == 0) return -1;

    // maxReach → farthest index we can reach so far
    // steps → steps we can still take before we must jump again
    // jumps → number of jumps made so far
    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    // Start from index 1 because we are already at index 0
    for (int i = 1; i < n; i++) {

        // If we have reached the last index, return total jumps
        if (i == n - 1)
            return jumps;

        // Update the farthest reachable index from here
        maxReach = max(maxReach, i + arr[i]);

        // Use one step to move forward
        steps--;

        // 🧠 If no more steps are left, we must jump again
        if (steps == 0) {
            jumps++; // we are using one more jump

            // If current index is equal to or beyond maxReach,
            // that means we cannot move forward → stuck
            if (i >= maxReach)
                return -1;

            // Reset the steps for the new jump range
            // The new steps = how many indices we can move from here
            steps = maxReach - i;
        }
    }

    // If we exit the loop without reaching the end
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << minJumps(arr);
    return 0;
}
