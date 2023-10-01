#include <iostream>
#include <map>
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

// Remove loop in linked list
//break the loop
Node* RemoveLoop(Node* &head){

    //if there is no node or only one node
    if(head == NULL || head->next == NULL){
        return head;
    }


    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            hasCycle = true;
            slow = head;
            break;
        }
    }
    
    //if there is no cycle
    if(!hasCycle){
        cout<<"There is no cycle in the linked list"<<endl;
        return NULL;
    }

    //remove cycle
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return head;

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
    Node* seventh = new Node(70);
    Node* eight = new Node(80);
    Node* ninth = new Node(90);
    Node* head = first;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = sixth;
    
    //remove loop
    RemoveLoop(head);

    cout<<"After removing loop"<<endl;
    print(head);
    

    

    
    return 0;
}