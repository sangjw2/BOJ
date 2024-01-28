#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;



// int compare(const void* a, const void* b) {
//     return strcmp(((Dict*)a)->name, ((Dict*)b)->name);
// }



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    string pokemon;
    unordered_map<int, string> pokeDict;
    unordered_map<string, int> pokeDict_str;

    cin >> n >> m;


    for(int i=1;i<=n;i++) {
        cin >> pokemon;
        pokeDict.insert(make_pair(i,pokemon));
        pokeDict_str.insert(make_pair(pokemon,i));
    }

    while(m--) {
        cin >> pokemon;

        if(isdigit(pokemon[0])) {
            cout << pokeDict[stoi(pokemon)] << '\n';
        } else {
            cout << pokeDict_str[pokemon] << '\n';
        }
    }

    return 0;
}