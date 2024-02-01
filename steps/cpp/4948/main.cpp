#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int a) {
    if(a==1) return false;
    for(long long int j=2;j*j<=a;j++) {
        if(a%j == 0) return false;
    }
    return true;
}



int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    vector<int> v;
    vector<int> primes;
    int cnt{0};
    
    while(true) {
        cin >> n;
        if(!n) break;
        v.push_back(n);
    }


    for(auto &i : v) {
        for(int j=sqrt(i*2);j>i;j--) {
            if(isPrime(j)) primes.push_back(j);
        }
        // 10000 -> 100 까지의 소수2 3 5 7 11
        for(auto &j : primes) {
            cout << j << " ";
        }
        cout << cnt << '\n';
        cnt=0;
    }
    
    // for(auto &i : v) {
    //     for(int j=i+1;j<=i*2;j++) {
    //         if(isPrime(j)) cnt++;
    //     }
    //     cout << cnt << '\n';
    //     cnt=0;
    // }

    return 0;
    
}