#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool validShuffle(string str1, string str2, string shuffle)
{
    int n1 = str1.size();
    int n2 = str2.size();
    int n = shuffle.size();

   
    if (n != n1 + n2)
        return false;

 
    unordered_map<char, int> freq;

    // Count characters in str1
    for (int i = 0; i < n1; i++)
        freq[str1[i]]++;

    // Count characters in str2
    for (int i = 0; i < n2; i++)
        freq[str2[i]]++;

    // Check shuffle characters
    for (int i = 0; i < n; i++) {
        if (freq.find(shuffle[i]) != freq.end())
            freq[shuffle[i]]--;
        else
            return false;
    }

    // Make sure all counts are zero
    for (auto it : freq) {
        if (it.second != 0)
            return false;
    }

    return true;
}

int main()
{
    string str1, str2, shuffle;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    cout << "Enter shuffle string: ";
    cin >> shuffle;

    if (validShuffle(str1, str2, shuffle))
        cout << " It is a valid shuffle of the two strings.\n";
    else
        cout << " It is NOT a valid shuffle.\n";

    return 0;
}
