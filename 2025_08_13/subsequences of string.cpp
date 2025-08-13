   #include <iostream>
using namespace std;

 
void generateSubsequences(string str, int index, string output) {
   
    if (index >= str.size()) {
        cout << output << endl;  
        return;
    }

    generateSubsequences(str, index + 1, output);

    generateSubsequences(str, index + 1, output + str[index]);
}

int main() {
    string str = "abc";
    cout << "All subsequences are:\n";
    generateSubsequences(str, 0, "");
    return 0;
}
