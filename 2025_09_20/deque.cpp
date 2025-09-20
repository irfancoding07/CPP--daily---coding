#include <iostream>
#include<queue>
using namespace std;

int main() {
    
    deque<int> d;
    
    d.push_front(12);
    d.push_back(14);
  
    cout << "size of an element " << d.size() << endl;
  
    cout << d.front() << endl;
    cout << d.back() << endl;
     
     d.pop_front();
     
     cout << d.front() << endl;
    cout << d.back() << endl;
    
    d.pop_back();
    
    if(d.empty()){
        cout << "queue empty hai mere dost" << endl;
    }
    else {
        cout << "queue empty nhi hai mere dost" << endl;
    }
    
    return 0;
}
