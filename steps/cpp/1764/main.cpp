#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n,m,cnt{0};
    string name;
    set<string> never_watched;
    set<string> both;
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> name;
        never_watched.insert(name);
    }

    for(int i=0;i<m;i++) {
        cin >> name;
        if(never_watched.count(name)) {
            both.insert(name);
            cnt++;
        }
    }

    cout << cnt << '\n';
    for(auto &i : both) {
        cout << i << '\n';
    }
    return 0;
}