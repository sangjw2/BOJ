#include <iostream>
#include <cstring>
using namespace std;

struct Dict {
    char name[20];
};

int compare(const Dict* a, const Dict* b){
    return strcmp(a->name, b->name);
}


int main() {
    Dict* myDict = new Dict[5];
    for(int i=0;i<5;i++) {
        cin >> myDict[i].name;
    }
    qsort((Dict*)myDict,5,sizeof(Dict),compare); // error

    delete[] myDict;
}