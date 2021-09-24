#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

bool isPrime(int num){
    if(num < 2 ) return false;
    if(num == 2) return true;
    for(int i=2; i<=sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main(){

    int n;
    queue<int> q;

    cin >> n;
    
    // xu ly

    for (int i = 2; i <= n, i < 10; i++){
        if (isPrime(i)){
            q.push(i);
        }
    }

    while(!q.empty()){
        for(int i=1; i<=9; i++){
            int sp = q.front()*10 + i ;
            if(sp <= n && isPrime(sp) ){
                q.push(sp);
            }
        }

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}