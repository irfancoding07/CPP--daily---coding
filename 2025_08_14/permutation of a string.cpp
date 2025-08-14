  #include <iostream>
using namespace std;


void permute(string &str, int start) {
    if (start >= str.size() ) {
        cout << str << endl;  
        return;
    }

    for (int i = start; i < str.size(); i++) {
        swap(str[start], str[i]);        
        permute(str, start + 1);          
        swap(str[start], str[i]);        
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Permutations of the string are" << endl;
    permute(s, 0);

    return 0;
}
