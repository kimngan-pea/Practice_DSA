#include<iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int num, QueueNode* ptr = NULL) {
        data = num;
        next = ptr;
    }
};

class Queue {
    private: 
    QueueNode* front;
    QueueNode* rear;

    public:
    Queue() {
        front = NULL;
        rear = NULL;
        cout << "An empty queue created.\n";
    }

    void Enqueue(int num) {
        if(isEmpty()) {
            front = new QueueNode(num);
            rear = front;
        } else {
            rear->next = new QueueNode(num);
            rear = rear->next;
        }
        cout << num << " enqueue.\n";
    }

    void Dequeue(int &num) {
        QueueNode* temp;
        if(isEmpty()) {
            cout << "Attemping dequeue an empty queue, exiting program...\n";
            exit(1);
        } else {
            num = front->data;
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        if(front != NULL) {
            return false;
        }
        return true;
    }

    void clear() {
        int data;
        while(!isEmpty()) {
            Dequeue(data);
        }
        cout << "Queue cleared.\n";
    }
};

int main() {
    Queue q;
    int num;
    cout << "Enter the queue (end by 0): \n";
    cin >> num;
    while(num != 0) {
        q.Enqueue(num);
        cin >> num;
    }
    cout << "the queue is: ";
    while(!q.isEmpty()) {
        q.Dequeue(num);
        cout << num << " ";
    }
    cout << "\n";
    q.clear();
    return 0;
}