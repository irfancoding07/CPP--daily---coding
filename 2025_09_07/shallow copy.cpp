   #include<iostream>
#include<cstring>
using namespace std;

class Hero {
    private:
    int health;
    public:
    char* name;
    char level;
    
    Hero(){
        cout<<"Simple comstructor called " <<endl;
        name = new char[100];
    }
    
    // Copy Constructor
    // Hero(Hero& temp) {
    //     cout << "Copy constructor called" << endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }
    
    void print() {
        cout << endl;
        cout << "[ Name: " << this->name<< " , ";
        cout << "health: " << this->health << " , ";
        cout << "level: " << this->level << " . ]";
        cout << endl<< endl;
    }
    
    int getHealth() {
        return health;
    }
    
    char getLevel() {
        return level;
    }
    
    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
    
    void setName (char name[]) {
        strcpy(this->name , name);
    }
};

int main() {

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    hero1.print();

 
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();

    return 0;
}
