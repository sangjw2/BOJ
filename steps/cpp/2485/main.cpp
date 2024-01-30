/*
#include <iostream>
using namespace std;


int euclidean(int a,int b) {
    int r = a%b;
    if(!r) return b;
    else return euclidean(b,r); //재귀
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,min,max,cnt{0},gcd;
    long int p;
    long int* pos;

    cin >> n;

    pos = new long int[n];
    for(int i=0;i<n;i++) {
        cin >> p;
        pos[i] = p;
        if(i==1){
            min = p-pos[i-1];
            max = p-pos[i-1];
        }
        
        if(i>1 && p-pos[i-1]<min) min = p-pos[i-1];
        if(i>1 && p-pos[i-1]>max) max = p-pos[i-1];
    }

    gcd = euclidean(min,max);

    // 추가로 심어줘야 할 가로수의 수 계산
    for (int i = 1; i < n; i++) {
        cnt += (pos[i] - pos[i-1]) / gcd+1;
    }

    cout << cnt-n;

    delete[] pos;
    return 0;
}
*/
#include <iostream>
using namespace std;

int euclidean(int a, int b) {
    int r = a % b;
    if (!r) return b;
    else return euclidean(b, r); // 재귀
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, min_interval, max_interval, cnt = 0, gcd;
    long int p;
    long int* pos;

    cin >> n;

    pos = new long int[n];
    for (int i = 0; i < n; i++) {
        cin >> p;
        pos[i] = p;
        if (i == 1) {
            min_interval = p - pos[i - 1];
            max_interval = p - pos[i - 1];
        }

        if (i > 1 && p - pos[i - 1] < min_interval) min_interval = p - pos[i - 1];
        if (i > 1 && p - pos[i - 1] > max_interval) max_interval = p - pos[i - 1];
    }

    gcd = euclidean(min_interval, max_interval);

    // 추가로 심어줘야 할 가로수의 수 계산
    for (int i = 1; i < n; i++) {
        cnt += (pos[i] - pos[i - 1]) / gcd + 1;
    }

    cout << cnt - n << '\n';

    delete[] pos;
    return 0;
}
