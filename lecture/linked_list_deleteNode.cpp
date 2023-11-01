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

void addTail(list& l, node* p) {
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void input(list& l) {
    int x;
    cout << "Enter the list (end by 0): ";
    while (1) {
        cin >> x;
        if (x <= 0) {
            return;
        }
        node* p = CreateNode(x);
        addTail(l, p);
    }
}

void output(list l) {
    cout << "The new list: ";
    node* p = l.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

// Delete after node q
void removeAfterQ(list& l, node* q) {
    if (q != NULL && q->next != NULL) {  // Check if q and q->next are not NULL.
        node* p = q->next;
        if (p == l.tail) {
            l.tail = q;
        }
        q->next = p->next;
        delete p;
    }
}

int main() {
    list l;
    input(l);
    int x;
    cout << "Enter the node q: ";
    cin >> x;
    node* q = NULL;
    //Find whether the node q exists or not in the list
    node* p = l.head;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            break;
        }
        p = p->next;
    }
    removeAfterQ(l,q);
    output(l);
    return 0;
}
