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

    void showStack();

    int size();

};

void Stack::push(int n) {
    if(top<maxSize) stackPointer[top++] = n;
    else cout << "Stack is Full.\n";
}

void Stack::pop() {
    if(top>0) {
        cout << stackPointer[top-1] << '\n';
        stackPointer[top--] = 0;
    }
    else cout << -1 << '\n';
}

void Stack::peek() {
    if(top>=0) cout << stackPointer[top-1] << '\n';
}

int Stack::size() {
    return top;
}

void Stack::showStack() {
    if(top>0) {
        for(int i{0};i<top;i++) {
            cout << stackPointer[i] << '\n';
        }
    } else cout << "Stack is Empty.\n";
}



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,t,x;
    cin >> n;
    Stack s(n);
    for(int i=0;i<n;i++) {
        cin >> t;
        switch(t) {
            case 1:
                cin >> x;
                s.push(x);
                break;
            case 2:
                if(s.size()==0) cout << -1 << '\n';
                else s.pop(); 
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                if(s.size()==0) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 5:
                if(s.size()==0) cout << -1 << '\n';
                else s.peek();
                break;
        }
    }

    return 0;
}