  #include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> st;
    
    // Transfer all elements from queue to stack
  while (!q.empty()) {
        int element = q.front();
        q.pop();
        st.push(element);
         
    }
    while (!st.empty()) {
         int element = st.top();
          st.pop();
        q.push( element);
    }
    
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
   
    reverseQueue(q);
    
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
return 0 ;
    
}
