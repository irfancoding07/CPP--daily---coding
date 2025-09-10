  #include <iostream>
using namespace std ;

class node {
    
    public :
    int data ;
    node* next ;
     
    
    node(int d){
        this -> data = d;
        this -> next = NULL;
         
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
 
  
   void insertnode(node* &tail, int element, int d){
       
       if(tail == NULL){
           node* temp = new node(d);
           tail = temp;
           temp -> next = temp;
       }
       else {
           node* curr = tail;
           
           while(curr->data !=element){
               curr = curr -> next;
           }
           
           node* temp = new node(d);
           temp->next = curr->next;
           curr-> next = temp;
       }
   }
   void print(node* tail) {
       
       node* temp = tail;
       
       do{
           cout << tail-> data << " ";
           tail = tail -> next;
       } while(tail != temp);
            cout << endl ; 
   }
   
    bool iscircularlist(node* head) {
        
        if (head == NULL) {
            return true;
        }
        
        node* temp = head -> next;
        while(temp !=NULL && temp != head) {
            temp = temp -> next;
        }
        if(temp == head){
            return true;
        }
        return false ;
            
    }
int main () {
    
    node* tail = NULL;
     
     insertnode(tail, 20, 30);
     print(tail);
     
     insertnode(tail, 30, 50);
     print(tail);
     
     insertnode(tail, 50, 70);
     print(tail);
     
     if(iscircularlist(tail)){
         cout << " linked list is circular is nature " << endl;
     }
     else{
          cout << "linked list is not a circular" << endl;
     }
     
    return 0;
}
