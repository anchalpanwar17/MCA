#include<bits/stdc++.h>
using namespace std;

#define MAX 5

int Stack[MAX];
int top = -1;

bool isFull(){
    return top == MAX-1;
}
bool isEmpty(){
    return top == -1;
}

void push(int num){
    if(isFull()){
        cout<<"Stack Overflow! Cannot push."<<endl;
    }
    Stack[++top] = num;
    return;
}

void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow! Cannot pop."<<endl;
    }
    top--;
}

void display(){
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

int main(){
    int choice;
    int data;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> data;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;

}