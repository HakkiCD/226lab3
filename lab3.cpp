#include <iostream>

using namespace std;

void swapValues(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i);
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

int findMax(int* arr, int size) {
    if (size <= 0) return -1;
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max)
            max = *(arr + i);
    }
    return max;
}

void reverseArray(int* arr, int size) {
    int* left = arr;
    int* right = arr + size - 1;
    while (left < right) {
        swapValues(left, right);
        left++;
        right--;
    }
}

int* createArray(int size) {
    int* arr = new int[size];
    return arr;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int main() {
    cout << "Creating dynamic array..." << endl << endl;

    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = createArray(size);

    cout << "Enter values: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }

    cout << "\nArray elements:" << endl;
    printArray(arr, size);

    cout << "\nMaximum element: " << findMax(arr, size) << endl;

    cout << string(40, '-') << endl;

    cout << "Swapping two numbers" << endl;
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapValues(&a, &b);
    cout << "After swap:  a = " << a << ", b = " << b << endl;

    cout << string(40, '-') << endl;

    cout << "Reversed array:" << endl;
    reverseArray(arr, size);
    printArray(arr, size);

    deleteArray(arr);
    return 0;
}