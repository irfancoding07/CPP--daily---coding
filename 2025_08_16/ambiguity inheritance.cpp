   #include<iostream>
using namespace std;

class A {

    public:
    void func () {
        cout << "i am IRFAN " << endl;
    }
};

class B  {
   public:
   void func() {
   cout << "i am zahid  " << endl;
   }
};

class C: public A, public B {
    
};
int main() {
       
       C obj;
      obj.A::func();
    return 0;
}
