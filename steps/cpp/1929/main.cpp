#include <iostream>
using namespace std;

bool isPrime(int a) {
    if(a==1) return false;
    for(long long int j=2;j*j<=a;j++) {
        if(a%j == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long int m,n;
    cin >> m >> n;

    for(long long int i=m;i<=n;i++) {
        if(isPrime(i)) cout << i << '\n';
    }
}