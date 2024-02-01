//
// Created by j1sang on 2024-01-30.
//
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(long long int a) {
    for(long long int i=2;i<=sqrt(a);i++) {
        if(a%i==0) return false;
    }
    return true;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long int t;
    long long int* nums;

    cin >> t;
    nums = new long long int[t];
    for(long long int i=0;i<t;i++) {
        cin >> nums[i];
    }

    for(long long int i=0;i<t;i++) {
        for(long long int j=nums[i];;j++) {
            if(j==0 || j==1) {cout << 2 << '\n'; break;}
            if(isPrime(j)) {cout << j << '\n'; break;}
        }
    }

    delete[] nums;
    return 0;
}
