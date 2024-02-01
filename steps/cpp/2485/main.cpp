#include <iostream>
using namespace std;


long int euclidean(long int a,long int b) {
    long int r = a%b;
    if(!r) return b;
    else return euclidean(b,r); //재귀
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    long int* pos;

    cin >> n;

    pos = new long int[n];
    for(int i=0;i<n;i++) {
        cin >> pos[i];
    }

    int temp = pos[1]-pos[0];

    for(int i=1;i<n-1;i++) {
        int next = pos[i+1]-pos[i];

        if(next > temp) {
            int swap = next;
            next = temp;
            temp = swap;
        }
        temp = euclidean(temp,next);
    }


    cout << ((pos[n-1]-pos[0])/temp)+1-n << '\n';


    delete[] pos;
    return 0;
}