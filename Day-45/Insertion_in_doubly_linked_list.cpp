#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(){
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data<< " ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }

    return len;
}

//insertion at head in doubly linked list
void insertAtHead(int data,Node* &head,Node* &tail){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//insertion at tail in doubly linked list
void insertAtTail(int data,Node* &head,Node* &tail){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

}

//insertion at given position in doubly linked list
void insertAtPosition(int data,int position,Node* &head,Node* &tail){

    Node* newNode = new Node(data);

    //if linked list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        insertAtHead(data,head,tail);
        return;
    }

    int len = getLength(head);

    if(position > len){
        insertAtTail(data,head,tail);
        return;
    }

    int i = 1;
    Node* prevNode = head;
    while (i < position-1)
    {
        prevNode = prevNode->next;
        i++;
    }

    // Node* curr = prevNode->next;

    // prevNode->next = newNode;
    // newNode->prev = prevNode;
    // newNode->next = curr;
    // curr->prev = newNode;


    //without using curr node.
    prevNode->next->prev = newNode;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;

    


}

int main(){
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    cout<<"Before Insertion:"<<endl;
    print(head);
    cout<<endl;

    insertAtHead(200,head,tail);
    insertAtTail(50,head,tail);

    insertAtPosition(100,3,head,tail);

    cout<<"After Insertion:"<<endl;
    print(head);


    return 0;
}