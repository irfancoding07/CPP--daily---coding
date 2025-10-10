  #include <iostream>
#include <queue>
using namespace std;
 
int main() {
     
    cout << "using priority queue here  " << endl;
    
    //maxheap
    priority_queue<int> pq;
    
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(5);
    
    cout << "element at top " << pq.top() << endl;
       
    pq.pop();
     cout << "element at top " << pq.top() << endl;
     cout << "size is " << pq.size() << endl;
    
    cout << endl;
    
    //minheap
    priority_queue<int, vector<int>, greater<int> > minheap;
     minheap.push(4);
    minheap.push(2);
    minheap.push(3);
    minheap.push(5);
    
    cout << "element at top " << minheap.top() << endl;
       
    minheap.pop();
     cout << "element at top " << minheap.top() << endl;
     cout << "size is " << minheap.size() << endl;
   
    return 0;
}
