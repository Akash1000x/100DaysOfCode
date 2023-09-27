#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Insertion at tail
void insertionAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

void insertionAtHead(Node* &head,int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        
    }
    newNode->next = head;
    head = newNode;
    return;
}

int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
    
}


void deletion(Node* &head,Node* &tail,int position){
    if(head == NULL){
        cout<<"Cannot delete, Linked list is empty";
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    
    if(position >= len){
        int i  = 1; 
        Node* prev = head;
        while(i<position-1){
            prev = prev->next;
            i++;
        }

        prev->next = NULL;
        Node* temp = tail;
        tail = prev;

        delete temp;

        return;

    }
    
    int i = 1;
    Node* prev = head;
    while(i<position-1){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    prev->next = curr->next;

    curr->next = NULL;

    delete curr;

}


// printing linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(2);
    Node *tail = head;
    // insertionAtHead(head,5);
    // insertionAtHead(head,8);
    // insertionAtHead(head,9);

    insertionAtTail(head,tail,4);
    insertionAtTail(head,tail,8);
    insertionAtTail(head,tail,12);

    cout<<"Before Deletion:"<<endl;
    print(head);
    cout<<endl;

    deletion(head,tail,2);

    cout<<"After Deletion:"<<endl;
    print(head);
    return 0;
}