#include<bits/stdc++.h>
int const n = 100;
using namespace std;


class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque( int capacity ) {
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
        this -> capacity = capacity;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
    void addFront( int element ) {
        if ( isFull() ) {
            cout << "Deque is full" << endl;
            return;
        }
        if ( front == -1 ) {
            front = 0;
            rear = 0;
        }
        else if ( front == 0 )
            front = capacity - 1;
        else
            front--;
        arr[front] = element;
        size++;
    }
    void addRear( int element ) {
        if ( isFull() ) {
            cout << "Deque is full" << endl;
            return;
        }
        if ( front == -1 ) {
            front = 0;
            rear = 0;
        }
        else if ( rear == capacity - 1 )
            rear = 0;
        else
            rear++;
        arr[rear] = element;
        size++;
    }
    void removeFront() {
        if ( isEmpty() ) {
            cout << "Deque is empty" << endl;
            return;
        }
        if ( front == rear ) {
            front = -1;
            rear = -1;
        }
        else if ( front == capacity - 1 )
            front = 0;
        else
            front++;
        size--;
    }
    void removeRear() {
        if ( isEmpty() ) {
            cout << "Deque is empty" << endl;
            return;
        }
        if ( front == rear ) {
            front = -1;
            rear = -1;
        }
        else if ( rear == 0 )
            rear = capacity - 1;
        else
            rear--;
        size--;
    }
    int getFront() {
        if ( isEmpty() ) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if ( isEmpty() || rear < 0 ) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    int getSize() {
        return size;
    }
    ~Deque() {
        delete[] arr;
    }
};
int main(){

    Deque de =  Deque( 5 );
    de.addFront( 3 );
    de.addRear( 4 );
    de.addRear( 5 );
    de.removeRear();
    de.addFront( 2 );
    de.removeFront();
    cout << de.isEmpty() << endl;
    
    // output
    // false
    return 0;
}
