 #include <iostream>
using namespace std;


char tolowercase(char ch){
    if(ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else {
        char temp = ch -'A' + 'a'; 
        return temp;
    }
}

  
  int getlength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}
  
bool isPalindrome(char name[]) {
      int n = getlength(name);
    int s = 0;
    int e =  - 1;

    while (s <= e) {
        if (tolowercase( name[s++] ) != tolowercase (name[e--]) ) {
            return false;
        }
        
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
