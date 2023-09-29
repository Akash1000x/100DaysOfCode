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
        ~Node(){
            cout<<"Node with data "<<this->data<<" is deleted"<<endl;
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

void deletionAtPosition(Node* &head,Node* &tail,int position){

    if(head == NULL){
        cout<< "Linked list is empty";
        return;
    }

    
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete(temp);
        return;
    }

    //delete at head
    if(position ==1){

        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next= NULL;
        delete(temp);
        return;
    }

    int len = getLength(head);

    //delete at tail    
    if(position == len){
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    //deletion at any position
    int i = 1;
    Node* curr = head;

    while(i < position){

        curr = head->next;
        i++;
    }

    Node* left = curr->prev;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->prev = NULL;
    curr->next = NULL;

    delete(curr);

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

    cout<<"Before Deletion:"<<endl;
    print(head);
    cout<<endl;

    deletionAtPosition(head,tail,1);
    
    cout<<"After Deletion:"<<endl;
    print(head);


    return 0;
}