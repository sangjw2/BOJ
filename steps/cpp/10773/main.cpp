#include <iostream>
using namespace std;

class Stack {
private:
    int maxSize;
    int* stackPointer{nullptr};
    int top{0};
public:
    Stack(int s) : maxSize{s} { // 생성자
        if(maxSize > 0 ) {
            if(stackPointer!=nullptr) delete[] stackPointer;
            stackPointer = new int[maxSize];
        }
        else cout << "Stack 크기로 0보다 큰 자연수를 입력하세요.\n";
        // cout << "스택 생성" << endl;
    }

    ~Stack() { // 소멸자
        if(stackPointer!=nullptr) delete[] stackPointer;
        // cout << "스택 소멸" << endl;
    }

    void push(int n);

    void pop();

    void peek();

    int sum();

    int size();

};

void Stack::push(int n) {
    if(top<maxSize) stackPointer[top++] = n;
    else cout << "Stack is Full.\n";
}

void Stack::pop() {
    if(top>0) {
        stackPointer[top--] = 0;
    }
}

void Stack::peek() {
    if(top>=0) cout << stackPointer[top-1] << '\n';
}

int Stack::size() {
    return top;
}

int Stack::sum() {
    int s{0};
    if(top>0) {
        for(int i{0};i<top;i++) {
            s += stackPointer[i];
        }
    }
    return s;
}



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,t;
    cin >> n;
    Stack s(n);
    for(int i=0;i<n;i++) {
        cin >> t;
        if(!t) s.pop();
        else s.push(t); 
    }

    cout << s.sum();
}