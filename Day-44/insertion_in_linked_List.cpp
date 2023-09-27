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
        // If the linked list is empty, both head and tail point to the new node
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

//Insertion at head
void insertionAtHead(Node* &head,int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        // If the linked list is empty, the new node becomes the head
        head = newNode;
        
    }
    // Otherwise, the new node is added at the beginning
    newNode->next = head;
    head = newNode;
    return;
}

// finding length of the Linked list
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

void insertionAtPosition(Node* &head,Node* &tail,int data,int position){

    Node* newNode = new Node(data);
    //whene linked list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    
    if(position == 1){
       insertionAtHead(head,data);
       return;
    }

    int len = findLength(head);

    if(position > len){
        insertionAtTail(head,tail,data);
        return;
    }

    //find prev and curr
    int i = 1;
    Node* prev = head;

    while(i < position-1){
        prev = prev->next;
        i++;
    }  

    // Insert the new node between 'prev' and 'curr'
    Node* curr = prev->next;

    newNode->next = curr;

    prev->next = newNode;

}

// printing linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        // Traverse and print each node's data
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

    cout<<"Before insertion:"<<endl;
    print(head);
    cout<<endl;

    insertionAtPosition(head,tail,20,4);

    cout<<"After insertion:"<<endl;
    print(head);
    return 0;
}