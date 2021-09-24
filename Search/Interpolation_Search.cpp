#include <iostream>

using namespace std;

int interpolation_Search(int arr[], int x, int n){

    int l = 0, r = n-1;

    while( arr[r] != arr[l] && x >= arr[l] && x <= arr[r] ){
        
        int mid = l + (r-l)*( (x-arr[l])/(arr[r]-arr[l]) );

        if( x < arr[mid]){
            r = mid - 1;
        }else if( x > arr[mid] ){
            l = mid + 1;
        }else{
            if(mid > 0 && arr[mid-1] == x){
                r = mid -1;
            }else{
                return mid;
            }
        }

    }

    if(arr[l] == x){
        return l;
    }

    return -1;

}


int main(){

    int n, a[99999], x;

    // cin >> n;
    n = 20;

    for(int i=0; i<n; i++){
        // cin >> a[i];
        a[i] = i;
    }

    // cin >> x;
    x = 9;
    
    cout << "interpolation search = " << interpolation_Search(a, x, n);

    return 0;
}