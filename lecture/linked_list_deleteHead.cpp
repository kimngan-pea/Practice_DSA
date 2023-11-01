#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

struct list {
    node* head = NULL;
    node* tail = NULL;
};

node* CreateNode(int x) {
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addTail(list &l, node *p) {
    if(l.head == NULL) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void input(list &l) {
    int x;
    cout << "Enter the list: ";
    while(1) {
        cin >> x;
        if(x <= 0) {
            return;
        }
        node* p = CreateNode(x);
        addTail(l,p);
    }
}

void output(list l) {
    node* p = l.head;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

//delete head
void removeHead(list &l) {
    node* p;
    if(l.head != NULL) {
        p = l.head;
        l.head = l.head->next;
        delete p;
        if(l.head == NULL) {
            l.tail = NULL;
        }
    }
}

int main() {
    list l;
    input(l);
    removeHead(l);
    cout << "The new list: ";
    output(l);
    return 0;
}