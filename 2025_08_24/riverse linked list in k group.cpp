  #include <iostream>
using namespace std;

class Node{
public:
      int data;
      Node* next;
      
      Node(int data){
          this ->data = data;
          this -> next =NULL;
      }
  };

 
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    
    Node* temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k){
       return head;    
    }  
    curr = head;
    count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    
    if (next) {
        head->next = reverseKGroup(next, k);
    }

     
    return prev;
}

void print(Node* head) {
       
       Node* temp = head;
       
       while(temp != NULL){
           cout << temp->data << " ";
           temp = temp->next;
       }
       cout << endl;
       }

int main() {
     
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    cout << "Original List" << " ";
    print(head);

    head = reverseKGroup(head, 3);

    cout << "Reversed in groups of 3" << " ";
    print(head);

    return 0;
}
