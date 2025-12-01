#include <iostream>
#include <limits>
using namespace std;    

class ArraySwapper {
private:
    int* data;
    int size;
public:
    ArraySwapper(int* arr, int s) : data(arr), size(s) {}
    // pointer-to-object: class uses raw pointer internally
    bool swapIndices(int i, int j) {
        if (i < 0 || j < 0 || i >= size || j >= size) 
            return false;
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        return true;
    }
};
void swapWithPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapWithReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void printArray(int* arr, int size, const string& msg) {
    cout << msg << '\n';
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int readIndex(const string& prompt, int maxIndex) {
    int index;
    while (true) {
        cout << prompt;
        cin >> index;
        if (cin.fail() || index < 0 || index > maxIndex) {
            cout << "Invalid index. Please enter a number between 0 and " << maxIndex << ".\n";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return index;
            
        }
    }
}

int main () {
    int size;
    cout << "Enter the size of the array: ";
    while (true) {
        cin >> size;
        if (cin.fail() || size <= 0) {
            cout << "Invalid size. Please enter a positive integer: ";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            break;
        }
    }

    int* arr = new int[size];

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    printArray(arr, size, "\nInitial array:");

    //--------------------------------------------------------
  
    int i = readIndex("\nEnter index of first element to swap (POINTER): ", size - 1);
    int j = readIndex("Enter index of second element to swap (POINTER): ", size - 1);

    cout << "\n--- Swapping using POINTERS ---\n";
    cout  << "Before Swap: arr[" << i << "]=" << arr[i] << ", arr[" << j << "]=" << arr[j] << '\n';
    swapWithPointers(&arr[i], &arr[j]);
    cout << "After  Swap: arr[" << i << "]=" << arr[i] << ", arr[" << j << "]=" << arr[j] << '\n';

    printArray(arr, size, "Array after POINTER swap:");

    //--------------------------------------------------------

    i = readIndex("\nEnter index of first element to swap (REFERENCE): ", size - 1);
    j = readIndex("Enter index of second element to swap (REFERENCE): ", size - 1);
    cout << "\n--- Swapping using REFERENCES ---\n";
    cout << "Before Swap: arr[" << i << "]=" << arr[i] << ", arr[" << j << "]=" << arr[j] << '\n';
    swapWithReferences(arr[i], arr[j]);
    cout<< "After  Swap: arr[" << i << "]=" << arr[i] << ", arr[" << j << "]=" << arr[j] << '\n';
    printArray(arr, size, "Array after REFERENCE swap:");
         
    ArraySwapper swapper(arr, size);
    i = readIndex("\nEnter index of first element to swap (CLASS): ", size- 1);
    j = readIndex("Enter index of second element to swap (CLASS): ", size - 1);
    cout << "\n--- Swapping using CLASS with RAW POINTER ---\n";
    cout  << "Before Swap: arr[" << i << "]=" << arr[i] << ", arr[" << j << "]=" << arr[j] << '\n';
    if (swapper.swapIndices(i, j)) {
        std::cout << "After  Swap: arr[" << i << "]=" << arr[i] << ", arr[" << j << "]=" << arr[j] << '\n';
    } else {
        std::cout << "Swap failed due to invalid indices.\n";
    }
    printArray(arr, size, "Array after CLASS swap:");
    //--------------------------------------------------------  
    // Clean up
    delete[] arr;
    return 0;




}
