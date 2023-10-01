//Insert a node after a element node in linked list

#include <iostream>
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


//insert into tail
void addTail(list &l, node* p) {
    if(l.head == NULL) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void input(list &l) {
    int x;
    cout << "Enter the list (end by 0): ";
    while(1) {
        cin >> x;
        if(x <= 0) {
            return;
        }
        node* p = CreateNode(x);
        addTail(l,p);
    }
}


//insert into head
void addHead(list &l, node* p) {
    if(l.head == NULL) {
        l.head = l.tail = p;
    } else {
        p->next = l.head;
        l.head = p;
    }
}


//insert after node q
void insertAfterQ(list &l) {
    int x, y;
    cout << "Enter the new element which insert into the list: ";
    cin >> x;
    node* p = CreateNode(x);
    cout << "Enter the element which inserted after in the list: ";
    cin >> y;
    node* q = l.head;
    while(q != NULL) {
        if(q->data == y) {
            p->next = q->next;
            q->next = p;
            if(l.tail == q) {
                l.tail = p;
            }
            return;
        } 
        else {
            q = q->next;
        }
    }
    addHead(l,p);
}

void output(list l) {
    node* p = l.head;
    cout << "The new list: ";
    while(p != NULL) {
        cout << p->data <<  " ";
        p = p->next;
    }
}

int main() {
    list l;
    input(l);
    insertAfterQ(l);
    output(l);
    return 0;
}
