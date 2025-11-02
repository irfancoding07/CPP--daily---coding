#include <iostream>
#include <vector>
using namespace std;

 
void rearrange(vector<int>& arr) {
    vector<int> pos, neg;

    // Step 1  Separate positive and negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);  // store positive number
        else
            neg.push_back(arr[i]);  // store negative number
    }

    
    int posIdx = 0;  // for positive array
    int negIdx = 0;  // for negative array
    int i = 0;       // for main array

    // Step 3 Place positive and negative numbers alternately
    while (posIdx < pos.size() && negIdx < neg.size()) {
        if (i % 2 == 0)
            arr[i++] = pos[posIdx++];  // even index → positive
        else
            arr[i++] = neg[negIdx++];  // odd index → negative
    }

    // Step 4 If positives remain, put them at the end
    while (posIdx < pos.size())
        arr[i++] = pos[posIdx++];

    // Step 5  If negatives remain, put them at the end
    while (negIdx < neg.size())
        arr[i++] = neg[negIdx++];
}

int main() {
    vector<int> arr = {1, 2, 3, -4, -1, 4};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    rearrange(arr);

    cout << "Rearranged array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
