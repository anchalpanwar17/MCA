// Implement stacks and queues using linked list.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

struct Stack{

    Node* head;
    int size;

    Stack(){
        head = NULL;
        size = 0;
    }

    bool isEmpty(){
        return head == NULL;
    }

    int isSize(){
        return size;
    }

    int top() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return -1; 
        }
        return head->data; 
    }

    void push(int data){
        Node* newNode = new Node(data);
        if (!newNode) {
            cout << "Stack Overflow. "<<endl;
        }
        newNode->next = head; 
        size++;
        head = newNode;
    }

    int pop(){
        if(isEmpty()){
            cout<<"The stack is empty. "<<endl;
            return -1;
        }
        int res = head->data;
        head = head->next;
        size--;
        return res;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

struct Queue{
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
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }
        int result = front->data;
        front = front->next;
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
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
   Stack s;
    Queue q;
    int choice, value;

    while (true) {
        // Display main menu options
        cout << "\nMenu:" << endl;
        cout << "1. Stack Operations" << endl;
        cout << "2. Queue Operations" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Stack Operations Menu
            int stackChoice;
            while (true) {
                cout << "\nStack Operations Menu:" << endl;
                cout << "1. Push element" << endl;
                cout << "2. Pop element" << endl;
                cout << "3. Display stack" << endl;
                cout << "4. Get top element" << endl; // Added top option
                cout << "5. Go back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> stackChoice;

                switch (stackChoice) {
                    case 1:
                        cout << "Enter value to push: ";
                        cin >> value;
                        s.push(value);
                        cout << value << " has been pushed onto the stack." << endl;
                        break;

                    case 2:
                        value = s.pop();
                        if (value != -1) {
                            cout << value << " has been popped from the stack." << endl;
                        }
                        break;

                    case 3:
                        cout << "Current stack: ";
                        s.display();
                        break;

                    case 4: // Get top element
                        value = s.top();
                        if (value != -1) {
                            cout << "Top element is: " << value << endl;
                        }
                        break;

                    case 5:
                        cout << "Returning to main menu..." << endl;
                        goto mainMenu;  // Jump back to the main menu

                    default:
                        cout << "Invalid choice, please try again." << endl;
                }
            }
        } else if (choice == 2) {
            // Queue Operations Menu
            int queueChoice;
            while (true) {
                cout << "\nQueue Operations Menu:" << endl;
                cout << "1. Enqueue element" << endl;
                cout << "2. Dequeue element" << endl;
                cout << "3. Display queue" << endl;
                cout << "4. Get front element" << endl; // Added front option
                cout << "5. Get back element" << endl; // Added back option
                cout << "6. Go back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> queueChoice;

                switch (queueChoice) {
                    case 1:
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        q.enqueue(value);
                        cout << value << " has been enqueued." << endl;
                        break;

                    case 2:
                        value = q.dequeue();
                        if (value != -1) {
                            cout << value << " has been dequeued." << endl;
                        }
                        break;

                    case 3:
                        cout << "Current queue: ";
                        q.display();
                        break;

                    case 4: // Get front element
                        value = q.getFront();
                        if (value != -1) {
                            cout << "Front element is: " << value << endl;
                        }
                        break;

                    case 5: // Get back element
                        value = q.getBack();
                        if (value != -1) {
                            cout << "Back element is: " << value << endl;
                        }
                        break;

                    case 6:
                        cout << "Returning to main menu..." << endl;
                        goto mainMenu;  // Jump back to the main menu

                    default:
                        cout << "Invalid choice, please try again." << endl;
                }
            }
        } else if (choice == 3) {
            cout << "Exiting program." << endl;
            exit(0);  // Exit the program
        } else {
            cout << "Invalid choice, please try again." << endl;
        }

        mainMenu:  // Label to return to the main menu
        continue;
    }

    return 0;
}