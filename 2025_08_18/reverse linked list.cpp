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
 
    node* reverselinkedlist(node* head){
        if(head == NULL  || head -> next == NULL) {
            return head;
        }
        
        node* prev = NULL;
        node* curr = head;
        node* forward = NULL;
        
        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main () {
     
       node* head = new node(1);
     head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    cout << "Original List: ";
    print(head);

    head = reverselinkedlist(head);

    cout << "reverselinkedlist: ";
    print(head);
     
    return 0;
}
