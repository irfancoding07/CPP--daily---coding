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
     
    return 0;
}
