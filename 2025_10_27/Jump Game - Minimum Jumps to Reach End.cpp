#include <iostream>
#include <vector>
using namespace std;

int minJumps(vector<int> &arr) {
    int n = arr.size();
    
    // If array has only one element, we are already at the end
    if (n <= 1) return 0;
    
    // If the first element is 0, we can't move anywhere
    if (arr[0] == 0) return -1;
    
    int maxReach = arr[0];  // The farthest we can reach initially
    int steps = arr[0];     // Steps available in the current jump
    int jumps = 1;          // We need at least one jump
    
  
    for (int i = 1; i < n; i++) {
        // If we've reached the end
        if (i == n - 1)
            return jumps;

        // Update the farthest reachable index
        maxReach = max(maxReach, i + arr[i]);
        
         
        steps--;
        
        // If no steps remain, we must jump
        if (steps == 0) {
            jumps++;   
            
            // If our current index is beyond what we can reach
            if (i >= maxReach)
                return -1;
            
            // Reset steps for the next jump
            steps = maxReach - i;
        }
    }
    
    return -1;  

int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << "Minimum number of jumps: " << minJumps(arr) << endl;
    return 0;
}
