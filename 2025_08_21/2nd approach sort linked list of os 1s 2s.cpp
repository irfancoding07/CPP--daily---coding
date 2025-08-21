   #include <iostream>
using namespace std ;

class node {
    
    public:
    int data ; 
    node* next;
    
    node(int data){
        this->data = data;
        this -> next = NULL;
    }
    
} ;


   void insertAttail(node* &tail, node* curr){
       tail-> next = curr;
       tail = curr;
   }
 
    node* sortlist(node* head){
        node* zerohead = new node(-1);
        node* zerotail = zerohead;
        node* onehead = new node(-1);
        node* onetail = onehead;
        node* twohead = new node(-1);
        node* twotail = twohead;
        
        node* curr = head;
        
        while (curr != NULL){
            
            int value = curr -> data;
            
            if (value == 0) {
                insertAttail(zerotail, curr);
            }
            else if (value == 1){
                insertAttail(onetail, curr);
            }
            else if (value == 2){
                insertAttail(twotail, curr);
            }
            curr = curr -> next;
        }
        
        if(onehead ->next != NULL){
            zerotail -> next = onehead->next;
        }
        
        else{
             zerotail -> next = twohead->next;
        }
        
        onetail->next = twohead->next;
        twotail->next = NULL;
        
      head = zerohead->next;
      
      delete zerohead;
      delete onehead;
      delete twohead;
      
      return head;
        
    }
    
      void print(node* head) {
       
       node* temp = head;
       
       while(temp != NULL){
           cout << temp->data << " ";
           temp = temp->next;
       }
       cout << endl;
      }
       
int main() { 
    node* head = new node(1);
    head->next = new node(0);
    head->next->next = new node(2);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(2);
    head->next->next->next->next->next = new node(0);
    

    cout << "orginal list" <<  " ";
     print(head);
     
     head = sortlist(head);
     
     cout <<" sorted list " << " ";
     print(head);

    return 0;
}
