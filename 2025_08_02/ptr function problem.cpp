  #include <iostream>
using namespace std ;

void print (int *p){
    
    cout << *p << endl;
}

void update(int *p){
    *p = *p+1;
}

int getsum(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}
 
int main() {
    
    int value = 5;
    int *p = &value;
    
   cout << " before " << *p << endl;
   update(p);
   cout <<" after " << *p << endl;
     
     
      int arr[5] = {1,2,3,4,5};
     
      cout << "sum is " << getsum(arr,5) << endl;
   return 0;
}
