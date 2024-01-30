#include <iostream>
using namespace std;

int euclidean(int a,int b) {
    int r = a%b;
    if(!r) return b;
    else return euclidean(b,r); //재귀
}

int main() {
    int a1,a2,b1,b2,lcm,gcd;
    cin >> a1 >> a2 >> b1 >> b2;
    lcm = (a2*b2) / euclidean(a2,b2); // 최소공배수
    a1 *= lcm/a2;
    b1 *= lcm/b2;
    a2=lcm; b2=lcm;

    a1 += b1;


    for(;;) { //기약분수화
        gcd=euclidean(a1,a2);
        if(gcd==1) break;
        a1 /= gcd;
        a2 /= gcd;
    }

    cout << a1 << " " << a2;

    return 0;
}