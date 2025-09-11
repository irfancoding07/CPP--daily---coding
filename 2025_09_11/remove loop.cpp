   #include <iostream>
    using namespace std ;

class node {
    
    public :
    int data ;
    node* next ;
    
    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAthead(node* &head, int d) {
    
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertAttail(node* &tail, int d) {
    
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
}
void print (node* &head) {
    node* temp = head ;
    
    while (temp != NULL ){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}


 void insertAtposition(node* &head,node* &tail, int position, int d){
     
     if (position == 1){
          insertAthead(head,d);
          return;
      }
     
     node* temp = head;
     int cnt = 1;
     
     while(cnt < position-1){
         temp = temp->next;
         cnt++;
     }
     
     if(temp -> next == NULL){
         insertAttail(tail,d);
         return;
     }
     
     node* nodeTOinsert = new node(d);
    nodeTOinsert -> next = temp -> next;
    temp -> next = nodeTOinsert;
     
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
    
     
    
     node* floyddetectloop(node* head){
         if(head == NULL){
             return NULL;
         }
         node* slow = head;
         node* fast = head;
         
         while (slow != NULL && fast!= NULL){
             
             fast = fast->next;
             if(fast != NULL){
                 fast = fast->next;
             }
             slow = slow->next;
             
             if(slow == fast){
                 cout << "present an element " << slow->data << endl;
                 return slow;
             }
             
         }
         return NULL;
     }
     
     node* getstartingnode(node* head){
         if(head == NULL){
             return NULL;
         }
         node* intersection = floyddetectloop(head);
         node* slow = head;
         while (slow != intersection){
             slow = slow->next;
             intersection = intersection->next;
         }
         return slow;
         
     }
     
     void removeloop(node* head){
         if(head == NULL){
             return;
         }
         node* startofloop = getstartingnode(head);
         node* temp = startofloop;
         while (temp-> next != startofloop){
             temp = temp->next;
         }
         temp -> next = NULL;
     }
     
int main () {
    
    node* node1 = new node(10);
      
      node* tail = node1;
      node* head = node1;
      print(head);
      
      insertAttail(tail, 12);
      print(head);
      
      insertAttail(tail, 15);
      print(head);
      
      insertAtposition(head,tail, 3, 22);
      print (head);
      
      tail ->next = head -> next;
      cout << "head" << head->data << endl;
      cout << "tail" << tail->data << endl;
      
      if (floyddetectloop(head)){
          cout << "cycle is present " << endl;
      }
      else {
          cout << " no cycle " << endl ;
      }
      
      node* loop = getstartingnode(head);
      cout << " loop starts at " << loop -> data << endl;
      
     removeloop(head);
      print(head);
      
      
    return 0;
}
