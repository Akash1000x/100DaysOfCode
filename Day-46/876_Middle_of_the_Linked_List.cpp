#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Node(){
    //     this->data = 0;
    //     this->next = NULL;
    // }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* findMiddle(Node* &head){

    //ll is empty
    if(head == NULL ){
        cout<<"linked is empty"<<endl;
        return head;
    }

    //ll has only one node
    if( head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(slow != NULL && fast!= NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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



    print(head);
    cout<<endl;

    cout<<"Middle Node is:"<<findMiddle(head)->data<<endl;

    return 0;
}