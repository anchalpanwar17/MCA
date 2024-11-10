#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

void menu(){
    cout<<"\n\tMENU : \n";
    cout<<"Press 1 to traverse the circular doubly LL\n"
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
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
}

void insertAtBeg(Node*& head, int data){
        if(head == nullptr){
                createHead(head, data);
                return;
        }
        Node* last = head->prev;
        Node* temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->prev = last;
        temp->next = head;
        last->next = temp;
        head->prev = temp;
        head = temp;
}

void insertAtEnd(Node*& head, int data){
        if(head == nullptr){
                createHead(head, data);
                return;
        }
        
        Node* newNode = (Node* )malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
}

void insertAtLoc(Node*& head, int data, int key){
        if(head == nullptr){
                cout<<"Linked List is empty."<<endl;
                return;
        }
        Node* temp = head;
        do{
            if(temp->data == key){
                Node* newNode = (Node* )malloc(sizeof(Node));
                newNode->data = data;
                newNode->prev = temp;
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }while(temp != head);
        cout<<"Key "<<key<<" not found in the list."<<endl;
}

void deleteAtBeg(Node*& head){
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
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
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
        temp->prev = temp->prev->prev;
        temp->prev->next = head;
}

void deleteAtLoc(Node*& head, int key){
        if(head == NULL){
                cout<<"List is empty.";
                return;
        }
        Node* temp = head;
        if(head->data == key){
            deleteAtBeg(head);
            return;
        }

        do{
            if(temp->data == key){
                if(temp->next == head){
                    deleteAtEnd(head);
                    return;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
            temp = temp->next;
        }while(temp != head);
        cout<<"Key "<<key<<" not found in the list"<<endl;
                
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