    #include <iostream>
using namespace std;

class node {
    
    public :
    int data ;
    node* next ;
     
    
    node(int d){
        this -> data = d;
        this -> next = NULL;
         
    }
};

  int getlength(node* head){
      
      int len = 0;
      while (head != NULL){
          len++;
          head = head -> next;
      }
      return len ;
  }
   
node* findMiddle(node* head) {
     int len = getlength(head);
     int ans = (len/2);
     
     node* temp = head;
     
     int cnt = 0;
     while(cnt < ans) {
         temp = temp-> next;
         cnt++;
     }
     return temp ;
}

int main() {
     
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    node* mid = findMiddle(head);
    cout << "Middle node value: " << mid->data << endl;

    return 0;
}
