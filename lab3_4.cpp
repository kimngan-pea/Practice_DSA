// Given:
// a is a multi-digit integer.
// b is a one-digit integer.
// Write a program to multiply these two integers using Stack.

// INPUT: 
// The first line is the integer a.
// The second line is the integer b.
// OUTPUT: 
// Print out the product of these two integers.

// Ví dụ:
// Input                      	                   
// 23
// 2
// Output  
// 46

#include<iostream>
using namespace std;

struct node {
    int data;
    node * next;
};

class stack {
    private:
    node* head;

    public:
    stack() {
        head = NULL;
    }

    node* createNode(int x) {
        node* p = new node;
        p->data = x;
        p->next = NULL;
        return p;
    }

    void addHead(node* p) {
        if(head == NULL) {
            head = p;
        } else {
            p->next = head;
            head = p;
        }
    }

    void push(int num) {
        node* p = createNode(num);
        addHead(p);
    }

    void pop(int &num) {
        if(isEmpty()) {
            return;
        }
        num = head->data;
        node* temp = head->next;
        delete head;
        head = temp;
    }

    bool isEmpty() {
        if(head != NULL) {
            return false;
        }
        return true;
    }

    void output() {
        node* p = head;
        while(p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main() {
    stack s;
    int a, b;
    cout << "Enter a multi-digit interger: ";
    cin >> a;
    s.push(a);
    cout << "Enter a one-digit integer: ";
    cin >> b;
    s.push(b);
    //push out the a and b to muultiply
    s.pop(a);
    s.pop(b);
    //push the product into the stack
    s.push(a * b);
    cout << "The product of these two integers is: ";
    s.output();
    return 0;
}

