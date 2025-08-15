 #include <iostream>

using namespace std ;

class hero {
    
    public:
    int health ;
    char level;
    
    hero(){
        cout << "constructor called" << endl;
    }
    
    hero(int health){
        cout << " this -> " << this << endl;
      this ->  health = health;
    }
    
    void print(){
        cout << level << endl;
    }
};
 
int main() {
     
     hero ramesh(10);
      cout << " address of ramesh " << &ramesh << endl;
      
     
     
    return 0;
}
