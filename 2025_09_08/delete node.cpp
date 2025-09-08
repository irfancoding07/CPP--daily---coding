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
    ~node(){
        int value = this -> data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
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
 
 void deletenode(int position, node* &head){
     
     if(position == 1){
         node* temp = head;
         head = head -> next;
         
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
         prev -> next = curr -> next;
         curr -> next = NULL;
         delete curr;
     }
     
 }
int main () {
    
    node* node1 = new node(5);
      
      node* tail = node1;
      node* head = node1;
      print(head);
      
      insertAttail(tail, 6);
      print(head);
      
      insertAttail(tail, 7);
      print(head);
      
      insertAtposition(head, 3, 8);
      print (head);
      
      deletenode(1, head);
      print (head);
    return 0;
}
