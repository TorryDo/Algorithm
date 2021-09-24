#include <iostream>

using namespace std;

// độ phức tạp th xấu nhất = n^2

int *insertionSort(int arr[], int n){

    int index, value;
    for(int i=1; i<n; i++){
        index = i;
        value = arr[i];

        while( index > 0 && arr[index-1] > value){
            arr[index] = arr[index-1];
            index--;
        }
        arr[index] = value;
    }

    return arr;
}

int main(){

    int n, a[9999];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int *b = insertionSort(a, n);

    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }

    return 0;
}