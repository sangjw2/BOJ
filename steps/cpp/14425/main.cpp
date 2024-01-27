#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    int n,m,c{0};
    string str;
    str.reserve(501);
    set<string> s;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> str;
        s.insert(str);
    }

    for(int i=0;i<m;i++) {
        cin >> str;
        if(s.count(str)) c++;
    }

    cout << c;


    return 0;
}