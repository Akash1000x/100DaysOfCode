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

    ~Node()
    {
        cout << "Node with data " << this->data << " is deleted" << endl;
    }
};


// finding length of the Linked list
int findLength(Node* &head){

    if(head == NULL){
        cout << "Linked List is empty."<<endl;
    }
    int len = 1;
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
        len++;
    }
    return len;
}

// inserting a Node in linked list
void insertionAtNode(Node* &head,int data,int PositionValue){

    Node* newNode = new Node(data);
    //whene linked list is empty
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    
    //when insertion value is head node
    if(head->data == PositionValue){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    int len = findLength(head);
    int i = 1;
    Node* prev = head;
    while(i<=len){
        if(prev->next->data == PositionValue){
            break;
        }
        prev = prev->next;
        i++;
    }
    if(i > len){
        cout<<"insert position value not present in linked list"<<endl;
        return;
    }
    Node* curr = prev->next;

    prev->next = newNode;
    newNode->next = curr;

    
}


// deleting node from linked list
void deleteNode(Node* &head,int node){
    //If linked list is empty
    if(head == NULL){
        cout << "Linked List is empty."<<endl;
    }

    //If linked list has only one node
    if(head->data == node && head->next == head){
        delete(head);
        return;
    }

    //If deletion value id head node
    if(head->data == node){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head->next = NULL;
        delete(head);
        head = temp->next;
        return;
    }
    //If linked list has more than one node
    int len = findLength(head);
    int i = 1;
    Node* prev = head;
    while(i<=len){
        if(prev->next->data == node){
            break;
        }
        prev = prev->next;
        i++;
    }
    if(i > len){
        cout<<"Given node is not present in linked list"<<endl;
        return;
    }
    Node* temp = prev->next;

    prev->next = temp->next;
    temp->next = NULL;

    delete(temp);

}

// printing linked list
void print(Node* &head)
{
    if(head == NULL){
        cout << "Linked List is empty.";
    }

    Node *temp = head;
    do
    {
        // Traverse and print each node's data
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

}

int main()
{
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* fourth = new Node(50);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = first;
    
    

    cout<<"Before:"<<endl;
    print(head);
    cout<<endl;

    insertionAtNode(head,60,50);

    deleteNode(head,20);


    cout<<"After:"<<endl;
    print(head);
    return 0;
}