#include<iostream>
using namespace std;

struct stackNode {
    int data;
    stackNode* next;
};

class stack {
    private:
    stackNode* top;

    public:
    stack() {
        top = NULL;
    } 
    
    void push(int x) {
        stackNode* Snode = new stackNode;
        Snode->data = x;
        if(isEmpty()) {
            top = Snode;
            Snode->next = NULL;
        } else {
            Snode->next = top;
            top = Snode;
        }
    }

    void pop(int &x) {
        stackNode* temp = new stackNode;
        if(isEmpty()) {
            cout << "The stack is empty!\n";
        } else {
            x = top->data;
            temp = top->next;
            delete top;
            top = temp;
        }
    }

    bool isEmpty() {
        if(top == NULL) {
            return true;
        }
        return false;
    }
};

int main() {
    stack S;
    cout << "Enter the stack array (end by 0): \n";
    int num;
    cin >> num;
    while(num != 0) {
        S.push(num);
        cin >> num;
    }
    cout << "Pushing successful!\n";
    cout << "Popping...\n";
    while(!S.isEmpty()) {
        S.pop(num);
        cout << num << "\n";
    }
    cout << "Finish!\n";
    return 0;
}

