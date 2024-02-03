#include <iostream>
using namespace std;

class Stack {
private:
    int size;
    int index;
    int* ptr;
public:
    Stack(int s) : size(s) {
        if(ptr!=nullptr) delete[] ptr; // 기존에 있으면 삭제
        else {
            ptr = new int[size];
            index = 0;
        }
    }
    ~Stack() {
        if(ptr!=nullptr) delete[] ptr;
    }

    void push(int a){
        if(index<size) {
            *(ptr+(index++)) = a;
        } else cout << "Stack is Full.\n";
    }

    bool pop() {
        if(index>0) {
            *(ptr+(index--)) = 0;
            return true;
        } else {
            return false;
        }
    }

    int getIndex() {
        return index;
    }
};

int getLength(char* n) {
    int length{0};
    while(*(n+length)!='\0') {
        length++;
    }
    return length;
}

bool checkVPS(char* s) {
    int cnt{0};
    int len = getLength(s);
    Stack ps(len);
    for(int i=0;i<len;i++) {
        if(*(s+i)=='(') {
            ps.push(1);
        } else { // ) 일 경우
            if(!(ps.pop())) {
                return false;
            }
        }
    }
    if(ps.getIndex()>0) return false;

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    char** strings;

    cin >> t;
    strings = new char*[t];

    for(int i=0;i<t;i++) {
        strings[i] = new char[51];
    }



    for(int i=0;i<t;i++) {
        cin >> strings[i];
    }
    for(int i=0;i<t;i++) {
        if(checkVPS(strings[i])) cout << "YES\n";
        else cout << "NO\n";
    }




    for(int i=0;i<t;i++){
        delete[] strings[i];
    }
    delete[] strings;

    return 0;
}