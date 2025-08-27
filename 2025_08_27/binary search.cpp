  #include <iostream>
using namespace std;

   int binarySearch(int arr[], int size, int key){
       
       int start = 0;
       int end = size-1;
       
       int mid = start + (end-start)/2;
       
       while (start<=end){
       
       if(arr[mid] == key){
           return mid;
       }
       else if (key > arr[mid]){
           start = mid +1;
       }
       else {
           end = mid -1;
       } 
       mid = start+ (end-start)/2;
       }
       return -1;
       
   }
int main() {
 
 int even[5] = {1,2,3,4,5};
 int odd[6] = {1,2,3,4,5,6};
 
 
 
    int evenindex = binarySearch(even, 6, 3);
    cout <<"index of 3 is " << evenindex << endl;
    
    int oddindex = binarySearch(odd, 5, 10);
    cout <<"index of 3 is " << oddindex << endl;
    
    
 
    return 0;
}
