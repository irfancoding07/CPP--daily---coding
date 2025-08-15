  #include <iostream>

using namespace std ;

class hero {
    
    public:
    int health ;
    char level;
    
    
    void print(){
        cout << level << endl;
    }
};
 
int main() {
     
     hero ramesh;
     cout << "size of ramesh is " << sizeof(ramesh) << endl;
     
     
     ramesh.health = 70;
     ramesh.level = 'A';
     
     cout << "health is:" << ramesh.health << endl;
     cout << "level is:" << ramesh.level << endl;
     
     
     
    return 0;
}
