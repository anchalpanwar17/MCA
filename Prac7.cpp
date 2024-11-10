#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int data){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* mergeSortedLists(Node* head1, Node* head2){
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;

    Node* mergedHead = nullptr; //creating a pointer of type Node pointing to NULL

    if(head1->data < head2->data){
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    
    Node* temp = mergedHead;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->data < head2->data){
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if(head1 != nullptr){
        temp->next = head1;
    } else {
        temp->next = head2;
    }

    return mergedHead;
}

void traverse(Node* head){
    if(head == nullptr){
        cout << "The linked list is empty." << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

int main(){
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int data;
    char choice;

    cout << "Enter elements for the first sorted linked list (in sorted order): " << endl;
    do{
        cout << "Enter element: ";
        cin >> data;
        insertAtEnd(head1, data);
        cout << "Do you want to enter another element for the first list? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    cout << "\n\nEnter elements for the second sorted linked list (in sorted order): " << endl;
    do{
        cout << "Enter element: ";
        cin >> data;
        insertAtEnd(head2, data);
        cout << "Do you want to enter another element for the second list? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    Node* mergedHead = mergeSortedLists(head1, head2);


    cout << "\nMerged sorted linked list: ";
    traverse(mergedHead);

    return 0;
}
