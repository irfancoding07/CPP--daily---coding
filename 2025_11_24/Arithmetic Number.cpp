#include <iostream>
using namespace std;

class Solution {
  public:
    int inSequence(int a, int b, int c) {
        if (c == 0) {
            return (a == b) ? 1 : 0;
        }

        if ((b - a) % c == 0 && (b - a) / c >= 0) {
            return 1;
        }
        return 0;
    }
};

int main() {
    int a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    Solution obj;
    int result = obj.inSequence(a, b, c);

    if (result == 1)
        cout << b << " is present in the sequence starting from " << a << " with common difference " << c << endl;
    else
        cout << b << " is NOT present in the sequence starting from " << a << " with common difference " << c << endl;

    return 0;
}
