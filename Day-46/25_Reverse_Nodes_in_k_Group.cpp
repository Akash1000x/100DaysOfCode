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

Node* reverseKNodes(Node* &head,int k){
    
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
        return NULL;
    }

    int len = findLength(head);
    if(k > len){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int i = 0; 
    while(i < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    if(forward != NULL){
        head->next = reverseKNodes(forward,k);
    }
    return prev;
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
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* head = first;
    Node* tail = sixth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;


    cout<<"Before reverse:"<<endl;
    print(head);
    cout<<endl;

    head = reverseKNodes(head,3);

    cout<<"After:"<<endl;
    print(head);

    

    
    return 0;
}