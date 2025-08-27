  #include <iostream>
using namespace std;

  void swapAlternate(int arr[], int size){
      for(int i = 0; i<=size; i+=2){
          if(i+1 < size){
              swap(arr[i], arr[i+1]);
          }
      }
  }
     
     void print (int arr[], int n){
         for(int i = 0; i<n; i++){
             cout << arr[i] << " ";
         }
         cout << endl;
     }
int main() {
 
 int even[5] = {1,2,3,4,5};
 int odd[6] = {1,2,3,4,5,6};
 
   swapAlternate(even,5);
   print(even,5);
   
    swapAlternate(odd,6);
    print(odd,6);
 
    return 0;
}
