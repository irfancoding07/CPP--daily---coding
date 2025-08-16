  #include <iostream>
using namespace std;
 
 class irfan {
     
     public:
     
     int weight;
     int age ;
     
      
     public:
      void speak() {
          cout << " hello " << endl;
      }
 };
 
  class zahid: public irfan {
      
  };
  
  class rahil : public zahid{
      
  };
 

int main() {
       
        rahil r;
       r.speak();
       
    return 0;
}
