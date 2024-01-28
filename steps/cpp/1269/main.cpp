#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n,m,num,acnt{0},bcnt{0};
    set<int> a,b;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> num;
        a.insert(num);
    }
    for(int i=0;i<m;i++) {
        cin >> num;
        b.insert(num);
    }
    for(auto &n : a) {
        if(b.count(n)) acnt++;
    }
    acnt = a.size()-acnt;
    for(auto &n : b) {
        if(a.count(n)) bcnt++;
    }
    bcnt = b.size()-bcnt;

    cout << acnt+bcnt;
    return 0;


}