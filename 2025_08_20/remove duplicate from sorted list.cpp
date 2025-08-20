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
 
       
node* uniqueshortedlist(node* head) {
    
    if(head == NULL)
    return NULL;
    
    node* curr = head ;
    
    while(curr != NULL) {
        
        if((curr -> next != NULL) && curr ->data == curr -> next ->data) {
            node* next_next = curr ->next->next;
            node* nodetodelete = curr->next;
            delete(nodetodelete);
            curr->next = next_next;
        }
        else {
            curr = curr->next;
        }
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
    head->next = new node(1);
    head->next->next = new node(2);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(3);
    head->next->next->next->next->next = new node(4);
       
     
     cout << "Original List: ";
     print(head);

    head = uniqueshortedlist(head);

    cout << "After Removing Duplicates: ";
    print(head);
       
    return 0;
}
