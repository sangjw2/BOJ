#include <iostream>
#include <cstring>
using namespace std;

struct Dict{
    char name[21];
};

int compare(const Dict* a,const Dict* b) {
    return strcmp(a->name, b->name);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    char pokemon[21];
    Dict* pokeDict;

    cin >> n >> m;
    pokeDict = new Dict[n];

    for(int i=0;i<n;i++) {
        cin >> pokeDict[i].name;
    }

    qsort(pokeDict, n, sizeof(Dict),compare); // error

    for(int i=0;i<m;i++) {
        cin >> pokemon;
        if(pokemon[0]>'9') {
            // 문자로 시작
            continue;
        }
    }

    delete[] pokeDict;
}