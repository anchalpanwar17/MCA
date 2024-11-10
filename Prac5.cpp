#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};


void menu(){
    cout<<"\n\tMENU : \n";
    cout<<"Press 1 to traverse the doubly LL\n"
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
        }else{
                while(temp){
                        cout<<temp->data<<" -> ";
                        temp = temp->next;
                }
                cout<<"null";
        }
}

void createHead(Node*& head, int data){
        Node* newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
}

void insertAtBeg(Node*& head, int data){
        if(head == nullptr){
                createHead(head, data);
                return;
        }
        Node* temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->prev = nullptr;
        temp->next = head;
        head = temp;
}

void insertAtEnd(Node*& head, int data){
        if(head == nullptr){
                createHead(head, data);
                return;
        }
        Node* temp = head;
        Node* newNode = (Node* )malloc(sizeof(Node));
        newNode->data = data;

        while(temp->next != nullptr){
                temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
}

void insertAtLoc(Node*& head, int data, int key){
        if(head == nullptr){
                cout<<"Linked List is empty."<<endl;
                return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->data != key){
                temp = temp->next;
        }
        if(temp->next == NULL){
                insertAtEnd(head, data);
                return;
        }
        if(temp == NULL){
                cout<<"Key "<<key<<" not found in the list."<<endl;
                return;
        }
        Node* newNode = (Node* )malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
}

void deleteAtBeg(Node*& head){
        if(head == NULL){
                cout<<"List is empty.";
                return;
        }
        Node* temp = head;
        head = temp->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        free(temp);
}

void deleteAtEnd(Node*& head){
        if(head == NULL){
                cout<<"List is empty.";
                return;
        }
        if(head->next == NULL){
                free(head);
                head = NULL;
                return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
                temp = temp->next;
        }
        temp->prev->next = NULL;

        free(temp);
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
        while(temp != nullptr && temp->data != key){
                temp = temp->next;
        }
        if(temp == NULL){
                cout<<"Key "<<key<<" not found in the list"<<endl;
                return;
        }
        if(temp->next == NULL){
                deleteAtEnd(head);
                return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->prev = NULL;
        temp->next = NULL;
        free(temp);
        
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
    }while(choice != 10);

    
    return 0;
}