//static queue
#include<iostream>
using namespace std;

class Queue {
    private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItem;

    public:
    Queue(int s) {
        queueArray = new int[s];
        queueSize = s;
        front = -1;
        rear = -1;
        numItem = 0;
        cout << "A queue with " << s << " elements created.\n";
    }

    void EnQueue(int num) {
        if(isFull()) {
            cout << "The queue is full." << num << " not enqueue.\n";
        } else {
            rear = (rear + 1) % queueSize;
            queueArray[rear] = num;
            numItem++;
            cout << num << " enqueue.\n";
        }
    }

    void DeQeue(int &num) {
        if(isEmpty()) {
            cout << "Attemping to dequeue on empty queue, exiting program...\n";
            exit(1);
        } else {
            front = (front + 1) % queueSize;
            num = queueArray[front];
            numItem--;
        }
    }

    bool isEmpty() const {
        if(numItem > 0) {
            return false;
        }
        return true;
    }

    bool isFull() const {
        if(numItem < queueSize) {
            return false;
        }
        return true;
    }

    void clear() {
        front = -1;
        rear = -1;
        numItem = 0;
        cout << "Queue cleared\n";
    }
};



int main() {
    int n;
    cout << "Enter the number of queue: ";
    cin >> n;
    Queue q(n);
    cout << "Enter the queue: \n";
    int num;
    while(!q.isFull()) {
        cin >> num;
        q.EnQueue(num);
    }
    cout << "The queue is: ";
    while(!q.isEmpty()) {
        q.DeQeue(num);
        cout << num << " ";
    }
    cout << "\n";
    q.clear();
    return 0;
}