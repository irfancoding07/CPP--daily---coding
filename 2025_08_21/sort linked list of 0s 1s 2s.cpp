    #include <iostream>
using namespace std ;

class node {
    
    public:
    int data ; 
    node* next;
    
    node(int d){
        this->data = d;
        this -> next = NULL;
    }
    
} ;
 
   node* sortlist(node* head){
       int zerocount = 0;
       int onecount = 0;
       int twocount = 0;
       
       node* temp = head;
       
       while(temp != NULL){
           if(temp->data == 0){
           zerocount++;
           }
           else if (temp-> data == 1)
           onecount++;
           else if (temp -> data == 2)
           twocount++;
               
               temp = temp->next;
           }
           
           temp = head;
           while(temp != NULL){
               if(zerocount != 0){
                   temp->data = 0;
                   zerocount--;
               }
               else if (onecount != 0){
                   temp->data = 1;
                   onecount--;
               }
               else if (twocount != 0){
                   temp->data = 2;
                   twocount--;
               }
               temp = temp->next;
               
           }
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
