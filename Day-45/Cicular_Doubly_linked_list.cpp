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

//print the linked list
void print(Node* &head){

    Node* temp = head;

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
}

int getLength(Node* &head){

    int len = 1;
    Node* temp = head->next;

    while(temp != head){
        temp = temp->next;
        len++;
    }

    return len;
}



//insertion at given position in doubly linked list
void insertion(int data,int PositionValue,Node* &head){

    Node* newNode = new Node(data);

    //if linked list is empty
    if(head == NULL){
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    //if insertion value is head node
    if(head->data == PositionValue){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = temp;
        head = newNode;
        return;
    }

    int len = getLength(head);
    int i = 1;
    Node* prevNode = head;
    while(i<=len){
        if(prevNode->next->data == PositionValue){
            break;
        }
        prevNode = prevNode->next;
        i++;
    }
    if(i > len){
        cout<<"insert position value not present in linked list"<<endl;
        return;
    }
    Node* currNode = prevNode->next;

    prevNode->next = newNode;
    newNode->next = currNode;
    newNode->prev = prevNode;
    currNode->prev = newNode;

}

//deletion at given position in doubly linked list
void deletion(int deleteNode,Node* &head){

    if(head == NULL){
        cout << "Linked list is empty" << endl;
    }

    //if linked list has only one node
    if(head->data == deleteNode && head->next == head){
        delete(head);
        return;
    }

    //if deletion value is head node   
    if(head->data == deleteNode){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        delete(head);
        head = temp->next;
        return;
    }

    //deletion from middle or end
    int len = getLength(head);
    int i = 1;

    Node* prevNode = head;
    while(i<=len){
        if(prevNode->next->data == deleteNode){
            break;
        }
        prevNode = prevNode->next;
        i++;
    }
    if(i>len){
        cout<<"delete node value not present in linked list"<<endl;
        return;
    }
    Node* currNode = prevNode->next;
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    delete(currNode);

}

int main(){
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* fourth = new Node(50);
    Node* head = first;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;
    
    fourth->next = first;
    first->prev = fourth;

    cout<<"Before:"<<endl;
    print(head);
    cout<<endl;



    // insertion(20,50,head);

    deletion(300,head);

    cout<<"After:"<<endl;
    print(head);


    return 0;
}