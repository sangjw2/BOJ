#include <iostream>
using namespace std;

long long int euclidean(long long int a, long long int b); // 유클리드 호제법

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    long long int gcd{0};
    long long int a,b;
    cin >> a >> b;


    gcd = euclidean(a,b);
    cout << a*b / gcd << '\n';

    return 0;
}



long long int euclidean(long long int a,long long int b) {
    long long int r = a%b;
    if(!r) return b;
    else return euclidean(b,r); //재귀
}