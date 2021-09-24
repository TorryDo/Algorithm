#include <iostream>

using namespace std;

// độ phức tạp th xấu nhất = n^2

int *selectionSort(int arr[], int n){

    int minIndex;
    for(int i=0; i<n; i++){
        minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        if( i != minIndex){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    return arr;
}

int main(){

    int n, a[9999];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int *b = selectionSort(a, n);

    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }

    return 0;
}