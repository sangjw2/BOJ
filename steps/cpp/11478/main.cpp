#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    set<string> s;
    int strlen{0},index{0};

    char str[1001];
    char another[1001]{0,};

    cin >> str;

    for(int i=0;;i++){ // str의 길이 구하기
        if(str[i]=='\0') {
            strlen = i;
            break;
        }
    }
    for(int i=0;i<strlen;i++) {
        for(int j=i;j<strlen;j++) {
            for(int m=i;m<j+1;m++){
                another[index++] = str[m];
            }
            another[index] = '\0';
            index=0;
            s.insert(another);

        }
    }
    cout << s.size();

    return 0;
}