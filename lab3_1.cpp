// Implement a stack using Single Linked List
// suppose that:
// push(a, s) is a function that pushes a to stack s.
// pop(s) is a function that removes an element from a stack.
// Given an integer x and a sequence of integers, write a program to do one of the following operations on the stack s conditionally on the value of each element of the integer sequence: 
// call push(a,s) if the element a of the sequence is different from x (a != x).
// call pop(s) if the element a of the sequence is equal to x (a=x). This operation is applied only when the stack is not empty.
// Print out elements of the stack s.

// Input:
// the first line is the number x.
// the next lines are elements of the sequence, separated by a new line (students use a linked list to store this sequence). The insertion is stopped when the program encounters a "0" input value (which is not added to the list).
// Output:
// If the stack is empty when calling pop operation, print out “Stack rong.”
// If the final stack is empty, print out “Stack rong.”
// else print out "Cac gia tri co trong stack la: " followed by elements of the stack separated by a space.

// Examples:
// Input
// 0

// 0
// Output
// Stack rong.

// Input
// 1

// 2

// 1

// 3

// 4

// 1

// 1

// 0
// Output
// Stack rong.

// Input
// 1

// 2

// 1

// 3

// 4

// 1

// 5

// 0
// Output
// Cac gia tri co trong stack la: 5 3

// Input
// 5

// 5

// 5

// 2

// 3

// 0
// Output
// Stack rong.

// Stack rong.

// Cac gia tri co trong stack la: 3 2
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[
]
template
###End banned keyword*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
struct stackNode {
    int data;
    stackNode* next;
};

struct stack {
    stackNode* head = NULL;
};


void push(int a, stack &s) {
    stackNode* p = new stackNode;
    p->data = a;
    p->next = NULL;
    if(s.head == NULL) {
        s.head = p;
    } else {
        p->next = s.head;
        s.head = p;
    }
}

void pop(stack &s) {
    stackNode* p = s.head;
    if(p == NULL) {
        cout << "Stack rong.\n";
    } else {
        s.head = s.head->next;
        delete p;
    }
}

void input(stack &s) {
    int x, a;
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap stack: \n";
    cin >> a;
    while(a != 0) {
        if(a != x) {
            push(a,s);
        } else {
            pop(s);
        }
        cin >> a;
    }
}


void output(stack s) {
    stackNode* p = s.head;
    if(p == NULL) {
        cout << "Stack rong.\n";
        return;
    } 
    cout << "Cac gia tri co trong stack la: ";
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    stack s;
    input(s);
    output(s);
    return 0;
}