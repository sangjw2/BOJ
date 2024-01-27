#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string name,status;
    set<string,greater<string>> online; //내림차순
    bool exist{false};
    
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> name >> status;
        exist = online.count(name);

        if(!exist && status=="enter") online.insert(name);
        else if(exist && status=="leave") online.erase(name);

    }

    for(auto &n : online) { cout << n << "\n";}
    
    return 0;
}