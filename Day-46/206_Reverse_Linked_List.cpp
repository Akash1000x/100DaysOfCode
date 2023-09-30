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

//reversing the linked list using recursion
Node* reversingUsingRecursion(Node* &prev,Node* &curr){

    //base case
    if(curr == NULL){
        return prev;
    }

    
    Node* forward = curr->next;
    curr->next = prev;

    return reversingUsingRecursion(curr,forward);    
}


//reverse using loops
Node* reversingUsingLoops(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
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
    Node* head = first;
    Node* tail = fourth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;



    cout<<"Before:"<<endl;
    print(head);
    cout<<endl;

    Node* prev = NULL;

    head = reversingUsingRecursion(prev,head);

    //or

    // head = reversingUsingLoops(head);



    cout<<"After reverse:"<<endl;
    print(head);
    return 0;
}