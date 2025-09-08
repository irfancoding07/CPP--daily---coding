   #include <iostream>
using namespace std ;

class node {
    
    public :
    int data ;
    node* next ;
    node* prev;
    
    node(int d){
        this -> data = d;
        this -> next = NULL;
        this-> prev = NULL;
    }
     
};

 void insertAthead(node* &head, int d) {
    
    node* temp = new node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
  
  void insertAttail(node* &tail, int d) {
    
    node* temp = new node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}
void print (node* head) {
    node* temp = head ;
    
    while (temp != NULL ){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;

}
  void insertAtposition (node* &head, node* tail, int position , int d){
      if (position == 1){
          insertAthead(head,d);
          return;
      }
      node* temp = head;
      int cnt = 1;
      
      while (cnt < position-1){
          temp = temp->next; 
          cnt++;
      }
      if(temp -> next == NULL){
         insertAttail(tail,d);
         return;
     }
      node* nodeTOinsert = new node(d);
     
    nodeTOinsert -> next = temp -> next;
    temp -> next ->  prev = nodeTOinsert;
    temp -> next = nodeTOinsert;
     nodeTOinsert ->prev = temp;
 
     
  }
int main () {
    
  node* node1 = new node(10);
      node* head = node1;
      node* tail = node1;
      
      insertAthead(head, 11);
      print(head);
      
      insertAthead(head, 16);
      print(head);
      
      insertAttail(tail,28);
      print(head);
      
      insertAtposition(tail, head, 2, 100);
      print(head);
       
    return 0;
}
