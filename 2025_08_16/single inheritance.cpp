 #include <iostream>
using namespace std;
 
 class animle {
     
     public:
     
     int weight;
     int age ;
     
     public:
      void speak() {
          cout << "speaking" << endl;
      }
 };
 
  class dog: public animle {
      
       
  };
 

int main() {
       
       dog d;
       d.speak();
       cout << d.age << endl;
    return 0;
}
