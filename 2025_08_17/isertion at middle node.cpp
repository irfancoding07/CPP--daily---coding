   #include <iostream>
using namespace std ;

class node {
    
    public :
    int data ;
    node* next ;
    
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAthead(node* &head, int d) {
    
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertAttail(node* &tail, int d) {
    
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
}
void print (node* &head) {
    node* temp = head ;
    
    while (temp != NULL ){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}


 void insertAtposition(node* &head, int position, int d){
     
     node* temp = head;
     int cnt = 1;
     
     while(cnt < position-1){
         temp = temp->next;
         cnt++;
     }
     
     node* nodeTOinsert = new node(d);
    nodeTOinsert -> next = temp -> next;
    temp -> next = nodeTOinsert;
     
 }
int main () {
    
    node* node1 = new node(10);
      
      node* tail = node1;
      node* head = node1;
      print(head);
      
      insertAttail(tail, 12);
      print(head);
      
      insertAttail(tail, 15);
      print(head);
      
      insertAtposition(head, 3, 22);
      print (head);
    return 0;
}
