// Implement a queue using a linked list.
// suppose that:
// enqueue(q, a) is a function that adds "a" to a queue q.
// dequeue(q) is a function that removes "a" from the queue q.
// Given a character c and a string s, write a program to do one of the following operations on the queue q conditionally on each character of the string s: 
// call enqueue(q, a) if character a of the string is different from c (a!=c).
// call dequeue(s) if character "a" of the string is equal to c (a=x). Print out the dequeued character. This operation is applied only when the queue is not empty.
// Print out the final queue.

// INPUT:
// The first line is the character c.
// The second line is the string s.

// Example:
// if the string s is an empty string print out "Chuoi rong.", else:
// the first line is dequeued elements.
// the second line is in the form "Cac gia tri co trong hang doi la: " followed by the final queue.
// If the queue is empty print out "Hang doi rong."

// Input
// B

// Output
// Chuoi rong.

// Input
// B

// ABCDBB
// Output
// ACD

// Hang doi rong.

// Input
// B

// ABCDBEF
// Output
// AC

// Cac gia tri co trong hang doi la: DEF
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
###End banned keyword*/
#include <string>
#include <iostream>
using namespace std;
struct node {
    char info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l);
node* CreateNode(char x);
void AddTail(List& l, node* p);
void Xuat(List l);
void enqueue(List& l, char x);
int dequeue(List& l);
bool isEmpty(List l);
int main()
{
    char c;
    cout << "Nhap ki tu dung de loai bo: ";
    cin >> c;
    cout << "Nhap chuoi: ";
    string s = "";
    cin >> s;
    List queue;
    CreateList(queue);
//###INSERT CODE HERE -
    if(s.empty()) {
        cout << "Chuoi rong.\n";
    }
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != c) {
            enqueue(queue, s[i]);
        } else {
            cout << (char) dequeue(queue);
        }
    }
    cout << "\n";
    Xuat(queue);
    return 0;
}

void CreateList(List& l) {
    l.pHead = l.pTail = NULL;
}

node* CreateNode(char x) {
    node* p = new node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(List& l, node* p) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void Xuat(List l) {
    node* p = l.pHead;
    if(isEmpty(l)) {
        cout << "Hang doi rong.\n";
        return;
    }
    cout << "Cac gia tri co trong hang doi la: ";
    while(p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void enqueue(List& l, char x) {
    node* p = CreateNode(x);
    AddTail(l,p);
}

int dequeue(List& l) {
    if(isEmpty(l)) {
        return 0;
    }
    node* p = l.pHead->pNext;
    int n = l.pHead->info;
    delete l.pHead;
    l.pHead = p;
    return n;
}

bool isEmpty(List l) {
    if(l.pHead != NULL) {
        return false;
    }
    return true;
}

