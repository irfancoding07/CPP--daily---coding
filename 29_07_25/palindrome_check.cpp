  #include <iostream>
using namespace std;

int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

bool isPalindrome(char name[]) {
    int n = getLength(name);
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        if (name[s] != name[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main() {
    char name[30];

    cout << "Enter a string: ";
    cin >> name;

    if (isPalindrome(name)) {
        cout << name << " is a palindrome." << endl;
    }
    else {
        cout << name << " is not a palindrome." << endl;
    }

    return 0;
}
