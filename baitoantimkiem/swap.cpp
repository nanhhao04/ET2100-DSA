#include <iostream>
using namespace std;
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min=a[0];
    int max= a[0];
    int imin, imax;
    for (int i = 0; i <n; i++) {
        if(a[i] <= min){
            min = a[i];
            imin = i;
            break;
        }
    }
    for (int i = 0; i <n; i++){
        if(a[i] >= max){
            max = a[i];
            imax = i;
        }
        }
    
    swap(a, imin, imax);
    for (int i = 0; i < n; i++) {
        cout << a[i] <<" ";
    }
    
    return 0;
}
