  #include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> st;
    
    // Transfer all elements from queue to stack
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    
    // Transfer all elements back from stack to queue
    // This reverses the order
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
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
