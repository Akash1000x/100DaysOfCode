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

//detect loop using floyd's cycle detection algorithm(it is also called tortoise and hare algorithm)  better approach
bool checkLoopByFCD(Node* &head){

    if(head == NULL){
        return false;
    }


    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            return true;
        }
    }
    return false;
}

//detect loop using hash map approach
bool checkForLoopByMap(Node* &head){
    map<Node*,bool> m;
    Node* temp = head;
    while(temp != NULL){
        if(m[temp] == true){
            return true;
        }
        m[temp] = true;
        temp = temp->next;
    }
    return false;
    

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
    ninth->next = fourth;

    // bool check = checkLoopByMap(head);

    //better approach
    bool check = checkLoopByFCD(head);

    if(check == 1){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }

    

    
    return 0;
}