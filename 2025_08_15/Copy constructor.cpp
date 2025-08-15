  #include <iostream>

using namespace std ;

class hero {
    
    public:
    int health ;
    char level;
    
    hero(){
        cout << "simple constructor called" << endl;
    }
    
    hero(int health){
      this ->  health = health;
    }
    
    hero(int health, char level){
      this ->  health = health;
      this -> level = level;
    }
    
    void print(){
        cout << "health" << this-> health << endl;
        cout << " level " << this-> level << endl;
    }
};
 
int main() {
     
 hero S(70, 'c');
 S.print();
 
 hero R(S);
 R.print();
    return 0;
}
