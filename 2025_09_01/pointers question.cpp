//1
#include <iostream>
using namespace std ;
int main() {
    int first = 110;
    int *p = &first;
    int **q = &p;
    int second = (**q)++  + 9;
    cout << first << " " << second << endl;

    return 0;
}


//2

#include <iostream>
using namespace std ;
int main() {
    int first = 120;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    cout << first << " " << second << endl;

    return 0;
}

//3

#include <iostream>
using namespace std ;

void increment(int **p){
    ++(**p);
}
int main() {
    int num = 100;
    int *ptr = &num;
    increment(&ptr);
    cout << num << endl;

    return 0;
}
