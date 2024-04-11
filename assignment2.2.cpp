#include<iostream>
using namespace std;

enum Color {Blue, Red, White};
// hàm swap
void swap(Color *a, Color *b) {
    Color temp = *a;
    *a = *b;
    *b = temp;
}

// quick sort
void quickSort(Color arr[], int low, int high) {
    if (low >= high) return; 
    Color pivot = arr[high]; // Chon phan tu cuoi lam pivot
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    int pi = (i + 1);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high); 
}

// Ham tron 2 mang da sap xep
void merge(Color arr1[], int size1, Color arr2[], int size2, Color result[]) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) { 
        if (arr1[i] < arr2[j]) result[k++] = arr1[i++];
        else result[k++] = arr2[j++];
    }
    while (i < size1) result[k++] = arr1[i++]; 
    while (j < size2) result[k++] = arr2[j++]; 
}

int main() {
    Color arr1[] = {Blue, Red, White, Red, Blue, White};
    int size1 = sizeof(arr1) / sizeof(Color);
    quickSort(arr1, 0, size1 - 1); 

    Color arr2[] = {Blue, Red, White};
    int size2 = sizeof(arr2) / sizeof(Color);
    quickSort(arr2, 0, size2 - 1); 

    Color result[size1 + size2];
    merge(arr1, size1, arr2, size2, result); 
    
    for (int i = 0; i < size1 + size2; i++) {
        switch (result[i]) {
            case Blue: cout << "Blue "; break;
            case Red: cout << "Red "; break;
            case White: cout << "White "; break;
        }
    }
    return 0;
}


