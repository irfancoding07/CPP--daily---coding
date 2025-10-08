 #include <iostream>
using namespace std;

// Heapify function for min-heap
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] < arr[smallest])
        smallest = left;
    if (right <= n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Delete root from min-heap
void deleteRoot(int arr[], int &size) {
    if (size == 0) {
        cout << "Heap is empty!" << endl;
        return;
    }

    arr[1] = arr[size]; // Replace root with last element
    size--;             // Reduce heap size
    heapify(arr, size, 1); // Restore heap property
}

 
void printHeap(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[100] = { -1, 2, 5, 3, 10, 7 };  
    int size = 5;  

    cout << "Original Heap: ";
    printHeap(heap, size);
 
    cout << "Heap after deletion: ";
    printHeap(heap, size);

    return 0;
}
