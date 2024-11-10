// Implement operations (enqueue, dequeue) on a queue using arrays. Check the status of the queue whether it is empty or full

#include <bits/stdc++.h>
using namespace std;

#define capacity 5

struct Queue{

    int *arr;
    int cnt;
    int rear;
    int front;

    Queue(){
        arr = new int[capacity];
        rear = -1;
        front = -1;
        cnt = 0;
    }

    bool isFull(){
        if (rear == capacity - 1)
            return true;
        return false;
    }

    bool isEmpty(){
        if (rear == -1 && front == -1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int elem){
        if (isEmpty())
        {
            front = 0;
        }
        else if (isFull())
        {
            cout << "Overflow! Queue is full."<<endl;
            return;
        }
        rear++;
        cnt++;
        arr[rear] = elem;
        return;
    }

    void dequeue(){
        if (isEmpty())
        {
            cout << "Underflow! Queue is empty."<<endl;
            return;
        }
        else if (rear == front)
        {
            rear = -1;
            front = -1;
            cnt = 0;
            return;
        }
        front++;
        return;
    }

    int frontIdx(){
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    int peek(){
        if (rear == -1)
        {
            return -1;
        }
        return arr[rear];
    }
};

int main(){
    Queue q;
    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Queue is Full\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Display Front Element\n";
        cout << "6. Display Peek Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                q.enqueue(element);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                cout << "Front element: " << q.frontIdx() << endl;
                break;
            case 6:
                cout << "Peek element: " << q.peek() << endl;
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != 0);

    return 0;
}
