// Implement a stack using a single linked list.
// Write a program to convert a positive integer from decimal to binary using Stack.

// INPUT: 
// a positive integer.
// OUTPUT: 
// print out the binary form of the number.

// Examples:
// Input
// 10
// Output
// 1010
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
###End banned keyword*/
#include <iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
};
void CreateList(List& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x);
void AddHead(List& l, node* p);
void enstack(List& l, int x);
void destack(List& l);
bool isEmpty(List l);
int main()
{
	List st;
	CreateList(st);
	long long x;
    cout << "Enter a positive integer: ";
	cin >> x;

//###INSERT CODE HERE -
    while(x) {
        enstack(st, x % 2);
        x /= 2;
    }
    destack(st);
    return 0;
}

node* CreateNode(int x) {
    node* p = new node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddHead(List& l, node* p) {
    if(l.pHead == NULL) {
        l.pHead = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void enstack(List& l, int x) {
    node* p = CreateNode(x);
    AddHead(l,p);
}

void destack(List& l) {
    cout << "The binary form of the number is: ";
    if(isEmpty(l)) {
        return;
    }
    node* p = l.pHead;
    while(p != NULL) {
        cout << p->info;
        p = p->pNext;
    }
}

bool isEmpty(List l) {
    if(l.pHead != NULL) {
        return false;
    } 
    return true;
}

