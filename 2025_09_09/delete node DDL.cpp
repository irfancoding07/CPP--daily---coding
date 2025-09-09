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
    ~node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << " memory free for node with data " << val << endl;
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

  void insertAtposition(node* &tail, node* &head, int position, int d){
     
      if(position == 1){
          insertAthead(head, d);
          return ;
      }
     node* temp = head;
     int cnt = 1;
     
     while(cnt < position-1){
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
 
  void deletenode(int position, node* &head){
     
     if(position == 1){
         node* temp = head;
         temp -> next ->prev = NULL;
         head = temp -> next;
         temp -> next = NULL;
         delete temp;
     }
     else {
         node* curr = head;
         node* prev = NULL;
         
         int cnt = 1;
         while(cnt < position){
             prev = curr;
             curr = curr -> next;
             cnt++;
         }
         curr -> prev = NULL;
         prev -> next = curr -> next;
        curr -> next = NULL;
         delete curr;
     }
     
 }
  
int main () {
    
    node* node1 = new node(5);
      node* head = node1;
      node* tail = node1;
      
      insertAttail(tail, 6);
      print(head);
      
      insertAttail(tail, 8);
      print(head);
      
      insertAttail(tail,9);
      print(head);
      
      insertAtposition(tail, head, 2, 100);
      print(head);
       
       deletenode(2, head);
    return 0;
}
