#include<bits/stdc++.h>
int const n = 100;
using namespace std;


class CircularQueue {
private:
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue( int capacity ) {
        this -> capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    bool isFull() {
        return size == capacity;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue( int value ) {
        if ( isFull() ) {
            cout << "Queue is full, cannot enqueue " << value << endl;
            return;
        }
        rear = ( rear + 1 ) % capacity;
        arr[rear] = value;
        size++;
        cout << "Enqueued " << value << endl;
    }
    int dequeue() {
        if ( isEmpty() ) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return -1;
        }
        int value = arr[front];
        front = ( front + 1 ) % capacity;
        size--;
        cout << "Dequeued " << value << endl;
        return value;
    }
    int getFront() {
        if ( isEmpty() ) {
            cout << "Queue is empty, no front element" << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if ( isEmpty() ) {
            cout << "Queue is empty, no rear element" << endl;
            return -1;
        }
        return arr[rear];
    }
    int getSize() {
        return size;
    }
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {

    CircularQueue cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cout << "Front: " << cq.getFront() << endl;
    cout << "Rear: " << cq.getRear() << endl;
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(6);
    cq.enqueue(7);
    cout << "Front: " << cq.getFront() << endl;
    cout << "Rear: " << cq.getRear() << endl;
    while ( !cq.isEmpty() ) {
        cq.dequeue();
    }
    cout << "Size: " << cq.getSize() << endl;
    
    return 0;
}

