#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};


void menu(){
    cout<<"\n\tMENU : \n";
    cout<<"Press 1 to traverse the LL\n"
        <<"Press 2 to insert at beginning\n"
        <<"Press 3 to insert at at end\n"
        <<"Press 4 to insert at location\n"
        <<"Press 5 to delete at beginning \n"
        <<"Press 6 to delete at end \n"
        <<"Press 7 to delete at location \n"
        <<"Press 8 to exit\n";
}

void traverse(Node*& head){
        Node* temp = head;
        if(head == nullptr){
            cout<<"The linked list is empty.";
            return;
        }
        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp != head);
        cout<<"null";
        
}

void createHead(Node*& head, int data){
        Node* newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = newNode;
        head = newNode;
}

void insertAtBeg(Node*& head, int data){
        if(head == nullptr){
                createHead(head, data);
                return;
        }
        Node* newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
}

void insertAtEnd(Node*& head, int data){
        if(head == nullptr){
                createHead(head, data);
                return;
        }
        Node* temp = head;
        Node* newNode = (Node* )malloc(sizeof(Node));
        newNode->data = data;

        while(temp->next != head){
                temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
}

void insertAtLoc(Node*& head, int data, int key){
        if(head == nullptr){
                cout<<"Linked List is empty."<<endl;
                return;
        }
        Node* temp = head;
        do {
            if(temp->data == key){
            Node* newNode = (Node* )malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while(temp != head);

    cout<<"Key "<<key<<" not found in the list."<<endl;
}

void deleteAtBeg(Node*& head){
        if(head == NULL){
                cout<<"List is empty.";
                return;
        }
        Node* temp = head;
        if(temp->next == head){
            free(head);
            head = NULL;
            return;
        }
        while(temp->next != head){
            temp = temp->next;
        }
        Node* toDel = head;
        temp->next = head->next;
        head = head->next;
        free(toDel);
}

void deleteAtEnd(Node*& head){
        if(head == NULL){
                cout<<"List is empty.";
                return;
        }
        if(head->next == head){
                free(head);
                head = NULL;
                return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while(temp->next != head){
                prev = temp;
                temp = temp->next;
        }
        prev->next = head;
        free(temp);
        temp = NULL;
}

void deleteAtLoc(Node*& head, int key){
        if(head == NULL){
                cout<<"List is empty.";
                return;
        }
        if(head->data == key){
                deleteAtBeg(head);
                return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        do{
            if(temp->data == key){
                prev->next = temp->next;
                free(temp);
                return;
            }
            prev = temp;
            temp = temp->next;
        }while(temp != head);

    cout<<"Key "<<key<<" not found in the list."<<endl;
}

int main(){

    Node* head = NULL;
    int choice, data, key;
    do{
        menu();
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch (choice){
            case 1: traverse(head);
                    break;
            case 2: cout<<"Enter the element : ";
                    cin>>data;
                    insertAtBeg(head, data);
                    break;
            case 3: cout<<"Enter the element : ";
                    cin>>data;
                    insertAtEnd(head, data);
                    break;
            case 4: cout<<"Enter the element : ";
                    cin>>data;
                    cout<<"Enter the element after which you want to insert : ";
                    cin>>key;
                    insertAtLoc(head, data, key);
                    break;
            case 5: deleteAtBeg(head);
                    break;
            case 6: deleteAtEnd(head);
                    break;
            case 7: cout<<"Enter the key you want to delete : ";
                    cin>>key;
                    deleteAtLoc(head, key);
                    break;
            case 8: exit(0);
                     break;
            default: cout<<"Invalid Choice";
        }
    }while(choice != 8);

    
    return 0;
}