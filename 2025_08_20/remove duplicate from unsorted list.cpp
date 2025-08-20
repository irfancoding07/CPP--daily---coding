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
};
 
       
node* removeDuplicatesunsorted(node* head) {
    
    if(head == NULL)
    return NULL;
    
    node* curr = head ;
    
    while(curr != NULL) {
         node* temp = curr;
           
           while(temp -> next != NULL) {
               if(temp ->next->  data == curr ->data) {
            node* nodetodelete = temp->next;
            temp->next = temp->next->next;
            delete nodetodelete;
        }
        else
        {
             temp = temp->next;
        }
           }
           curr = curr->next;
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
    
int main () {
    
       node* head = new node(1);
    head->next = new node(3);
    head->next->next = new node(2);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(4);
    head->next->next->next->next->next = new node(1);
    head->next->next->next->next->next->next = new node(5);

    cout << "Original List: ";
    print(head);

    head = removeDuplicatesunsorted(head);

    cout << "After Removing Duplicates: ";
    print(head);
    
     
       
    return 0;
}
