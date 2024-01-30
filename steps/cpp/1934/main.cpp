#include <iostream>
using namespace std;

int euclidean(int a, int b); // 유클리드 호제법

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int t,gcd{0};
    int* a;
    int* b;
    cin >> t;
    a = new int[t];
    b = new int[t];

    for(int i=0;i<t;i++) {
        cin >> a[i] >> b[i];
    }

    for(int i=0;i<t;i++) {
        gcd = euclidean(a[i],b[i]);
        cout << a[i]*b[i] / gcd << '\n';
    }
    delete[] a;
    delete[] b;

    return 0;
}



int euclidean(int a,int b) {
    int r = a%b;
    if(!r) return b;
    else return euclidean(b,r); //재귀
}