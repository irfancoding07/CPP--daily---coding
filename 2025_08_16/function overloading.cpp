 #include<iostream>
using namespace std;

class A {

    public:
    void sayhello () {
        cout << "hello irfan   " << endl;
        
    }
    int sayhello (char name) {
        cout << " i am irfan   " << endl;
        return 1;
    }
    
    void sayhello(string name){
        cout << "hello " << name <<  endl;
    }
};

 
int main() {
       
       A obj;
      obj.sayhello();
    return 0;
}
