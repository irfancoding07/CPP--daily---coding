 #include <iostream>
using namespace std;


   void selectionSort(int arr[], int n) {
     
    for (int i = 0; i < n - 1; i++) {

        int min_index = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_index]) {

                min_index = j;

            }

        }
        swap(arr[min_index], arr[i])
    }

}

int main() {

    int array[] = {98, 34,16, 22, 8};

    int n = sizeof(array) / sizeof(array[0]);

    selectionSort(array, n);

    cout << "Sorted array"<<endl;

    for (int i = 0; i < n; i++)

        cout << array[i] << " ";

 
    
    return 0;
}
