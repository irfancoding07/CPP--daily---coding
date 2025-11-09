#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        priority_queue<int> pq;   

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int curr = mat[i][j];
                pq.push(curr);

                // keep only k smallest elements in heap
                if (pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top(); // top element is kth smallest
    }
};

int main() {
    int n, k;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    int result = obj.kthSmallest(mat, k);

    cout << "\nThe " << k << "th smallest element is: " << result << endl;

    return 0;
