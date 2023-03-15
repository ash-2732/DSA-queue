#include<bits/stdc++.h>
int const n = 100;
using namespace std;



// Define the Node structure for the linked list
struct Node {
    int data;
    Node* next;
};
class CircularQueue {
private:
    Node* rear;
    int size;
public:
    // Constructor to initialize rear and size
    CircularQueue() {
        rear = nullptr;
        size = 0;
    }
    // Method to check if the queue is empty
    bool isEmpty() {
        return ( rear == nullptr );
    }
    // Method to add an element to the rear of the queue
    void enqueue( int value ) {
        Node* newNode = new Node;
        newNode -> data = value;
        if ( isEmpty() ) {
            newNode -> next = newNode;
            rear = newNode;
        } else {
            newNode -> next = rear -> next;
            rear -> next = newNode;
            rear = newNode;
        }
        size++;
    }
    // Method to remove an element from the front of the queue
    int dequeue() {
        if ( isEmpty() ) {
            cout << "Queue is empty" << endl;
            return -1;
        } else if ( rear -> next == rear ) {
            int value = rear -> data;
            delete rear;
            rear = nullptr;
            size--;
            return value;
        } else {
            Node* temp = rear -> next;
            int value = temp -> data;
            rear -> next = temp -> next;
            delete temp;
            size--;
            return value;
        }
    }
    // Method to display the elements in the queue
    void display() {
        if ( isEmpty() ) {
            cout << "Queue is empty" << endl;
        } else {
            Node* current = rear->next;
            while ( current != rear ) {
                cout << current -> data << " ";
                current = current -> next;
            }
            cout << current -> data << endl;
        }
    }
    // Method to get the size of the queue
    int getSize() {
        return size;
    }
};

int main() {

    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.display();

    return 0;
}


