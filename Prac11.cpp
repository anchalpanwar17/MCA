//  Implement circular queue using arrays and linked list.

#include<bits/stdc++.h>
using namespace std;

#define capacity 5

struct CircularQueueA{
    int *arr;
    int rear;
    int front;

    CircularQueueA(){
        arr = new int[capacity];
        rear = -1;
        front = -1;
    }

    bool isFull(){
        if((rear+1)%capacity == front) return true;
        return false;
    }   

    bool isEmpty(){
        if(front == -1 && rear == -1)
            return true;
        return false;
    }

    void enqueue(int data){
        if (isEmpty()){
            front = 0;
            rear = 0;
        }else if (isFull()){
            cout << "Overflow! Queue is full."<<endl;
            return;
        }else{
            rear = (rear+1)%capacity;
        }
        arr[rear] = data;
    }

    int dequeue(){
        int x = 0;
        if(isEmpty()){
            cout<<"Underflow! Queue is empty."<<endl;
            return -1;
        }else if(front == rear){
            x = arr[front];
            front = rear = -1;
        }else{
            x = arr[front];
            front = (front+1)%capacity;
        }
        return x;
    }

    int getFront(){
        if (isEmpty()){
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    int getBack(){
        if (isEmpty()){
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Array Circular Queue is empty." << endl;
            return;
        }
        cout << "Array Circular Queue: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;  // Print the rear element
    }


};

struct Node
{
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

struct CircularQueueLL{
    Node* front;
    Node* rear;

    bool isEmpty(){
        if(front == NULL) return true;
        return false;
    }

    void enqueue(int data){
        Node* newNode = new Node(data);
        if(isEmpty()){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        int result = front->data;
        front = front->next;
        rear->next = front;
        return result;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    int getBack() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return rear->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Linked List Circular Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Linked List Circular Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};


int main(){

   CircularQueueA queueArray;
    CircularQueueLL queueLinkedList;
    int choice, value, subChoice;

    while (true) {
        // Main menu
        cout << "\nMain Menu:" << endl;
        cout << "1. Circular Queue using Arrays" << endl;
        cout << "2. Circular Queue using Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Array Circular Queue Operations
                while (true) {
                    cout << "\nArray Circular Queue Menu:" << endl;
                    cout << "1. Enqueue element" << endl;
                    cout << "2. Dequeue element" << endl;
                    cout << "3. Get front element" << endl;
                    cout << "4. Get back element" << endl;
                    cout << "5. Display queue" << endl;
                    cout << "6. Go back to main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            queueArray.enqueue(value);
                            break;
                        case 2:
                            value = queueArray.dequeue();
                            if (value != -1) {
                                cout << value << " has been dequeued from the array circular queue." << endl;
                            }
                            break;
                        case 3:
                            value = queueArray.getFront();
                            if (value != -1) {
                                cout << "Front element: " << value << endl;
                            }
                            break;
                        case 4:
                            value = queueArray.getBack();
                            if (value != -1) {
                                cout << "Back element: " << value << endl;
                            }
                            break;
                        case 5:
                            queueArray.display();
                            break;
                        case 6:
                            cout << "Returning to main menu..." << endl;
                            goto mainMenu;  // Jump back to the main menu
                        default:
                            cout << "Invalid choice, please try again." << endl;
                    }
                }

            case 2:
                // Linked List Circular Queue Operations
                while (true) {
                    cout << "\nLinked List Circular Queue Menu:" << endl;
                    cout << "1. Enqueue element" << endl;
                    cout << "2. Dequeue element" << endl;
                    cout << "3. Get front element" << endl;
                    cout << "4. Get back element" << endl;
                    cout << "5. Display queue" << endl;
                    cout << "6. Go back to main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:
                            cout << "Enter value to enqueue: ";
                            cin >> value;
                            queueLinkedList.enqueue(value);
                            break;
                        case 2:
                            value = queueLinkedList.dequeue();
                            if (value != -1) {
                                cout << value << " has been dequeued from the linked list circular queue." << endl;
                            }
                            break;
                        case 3:
                            value = queueLinkedList.getFront();
                            if (value != -1) {
                                cout << "Front element: " << value << endl;
                            }
                            break;
                        case 4:
                            value = queueLinkedList.getBack();
                            if (value != -1) {
                                cout << "Back element: " << value << endl;
                            }
                            break;
                        case 5:
                            queueLinkedList.display();
                            break;
                        case 6:
                            cout << "Returning to main menu..." << endl;
                            goto mainMenu;  // Jump back to the main menu
                        default:
                            cout << "Invalid choice, please try again." << endl;
                    }
                }

            case 3:
                cout << "Exiting program." << endl;
                exit(0);  // Exit the program
            default:
                cout << "Invalid choice, please try again." << endl;
        }

        mainMenu:  // Label to return to the main menu
        continue;
    }

    return 0;
}
