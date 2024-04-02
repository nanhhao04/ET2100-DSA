#include <iostream>
using namespace std;
enum Color {
    red = 0,
    white = 1,
    blue = 2
};
int main(){
    int array[]={blue , red, blue, red, red, white, red, blue, white};
    //xanh, d?, xanh, d?, d?, tr?ng, d?, xanh, tr?
    int n = sizeof(array) / sizeof(array[0]);
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
        }
    }
    }
    //in m?ng theo th? t? các màu
    for (int i = 0; i < n; ++i) {
        if (array[i] == red) {
            cout << "red ";
        } else if (array[i] == white) {
            cout << "white ";
        } else if (array[i] == blue) {
            cout << "blue ";
        }
    }

    return 0;
}
