  #include <iostream>
using namespace std ;

bool Linearsearch(int arr[], int size, int key){
    if (size == 0)
    return false ;
    
    if (arr[0] == key ){
        return true;
    }
    else {
        bool remainingpart = Linearsearch(arr+1,size-1,key);
        return remainingpart;
    }
}
int main() {
   int arr[5] = {3,5,1,2,6};
    int size = 5;
    
    int key= 2;
      bool ans = Linearsearch(arr,size,key);
      
      if (ans){
          cout << "present" << endl;
      }
      else{
          cout << "not present" << endl;
      }

    return 0;
}
