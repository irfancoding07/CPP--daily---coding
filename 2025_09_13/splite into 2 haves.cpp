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

  void  splitlist (node* head,  node** firsthalf,  node** secondhalf){
      if(head == NULL || head->next == NULL){
      *firsthalf = head;
      *secondhalf = NULL;
      return ;
      }
      
      node* slow = head;
      node* fast = head->next;
      
      while (fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
      }
      
      *firsthalf = head;
      *secondhalf = slow->next;
      slow->next = NULL;
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
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);

    node* firstHalf = NULL;
    node* secondHalf = NULL;

    splitlist(head, &firstHalf, &secondHalf);

    cout << "First Half" << " " ;
    print(firstHalf);

    cout << "Second Half" << " ";
    print(secondHalf);

    return 0;
}
