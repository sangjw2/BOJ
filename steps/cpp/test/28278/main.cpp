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
        cout << "스택 생성" << endl;
    }

    ~Stack() { // 소멸자
        if(stackPointer!=nullptr) delete[] stackPointer;
        cout << "스택 소멸" << endl;
    }

    void push(int n);

    void pop();

    void peek();

    void showStack();

    int size();

};

void Stack::push(int n) {
    if(top<maxSize) stackPointer[top++] = n;
    else cout << "Stack is Full.\n";
}

void Stack::pop() {
    if(top>0) stackPointer[top--] = 0;
    else cout << "Stack is Empty.\n";
}

void Stack::peek() {
    cout << "top 원소: "<< stackPointer[top-1] << endl;
}

int Stack::size() {
    return top-1;
}

void Stack::showStack() {
    if(top>0) {
        for(int i{0};i<top;i++) {
            cout << stackPointer[i] << endl;
        }
    } else cout << "Stack is Empty.\n";
}

int main() {
    Stack s(3);
    s.push(5);
    s.peek();

    s.push(6);
    s.peek();

    s.pop();
    s.peek();

    s.push(7);
    s.peek();

    s.push(8);
    s.peek();

    s.showStack();

    return 0;
}