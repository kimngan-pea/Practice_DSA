#include<iostream>
using namespace std;

class stack {
    private:
    int* stackArray;
    int stackSize;
    int top;

    public:
    stack(int size) {
        stackArray = new int [size];
        stackSize = size;
        top = -1;
    }

    void push(int x) {
        if(isFull()) {
            cout << "The stack is full!\n";
        } else {
            top++;
            stackArray[top] = x;
        }
    }

    void pop(int &x) {
        if(isEmpty()) {
            cout << "The stack is empty!\n";
        } else {
            x = stackArray[top];
            top--;
        }
    }

    bool isFull() {
        if(top == stackSize - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
};

int main() {
    int n;
    cout << "Enter size of the stack array: ";
    cin >> n;
    stack S(n);
    cout << "Enter the array: \n";
    while(!S.isFull()) {  
        int num;
        cin >> num;
        S.push(num);
    }
    cout << "Pushing successful!\n";
    cout << "Popping...\n";
    while(!S.isEmpty()) {
        int num;
        S.pop(num);
        cout << num << "\n";
    }
    cout << "Finish!\n";
    return 0;
}