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

   void insertnode(node*& tail, int element, int d){
       if (tail == NULL){
           node* temp = new node(d);
           tail = temp;
           temp->next = temp;
       }
       else {
           node* curr = tail;
           while (curr-> data != element ){
               curr = curr -> next;
           }
           node* temp = new node(d);
           temp -> next = curr->next;
           curr -> next = temp;
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
   
   void deletenode (node* &tail, int value ){
       if (tail == NULL){
           cout << "list is empty, please check again"  << endl;
           return ;
       }
       else {
           node* prev = tail;
            node* curr  = prev -> next;
            
            while (curr->data != value){
                prev = curr;
                curr = curr -> next;
            }
            prev->next = curr->next;
            
            if(prev == curr){
                tail = NULL;
            }
            if (tail == curr){
                tail = prev;
            }
            curr -> next = NULL;
            delete curr;
            
       }
   }
   
int main () {
    
    node* tail = NULL;
     
     insertnode(tail, 5, 10);
     print(tail);
     
     insertnode(tail, 10, 20);
     print(tail);
     
     insertnode(tail, 20, 30);
     print(tail);
     
     insertnode(tail, 20, 40);
     print(tail);
     
     insertnode(tail, 10, 90);
     print(tail);
     
      deletenode(tail, 30);
     print(tail);
    return 0;
}
