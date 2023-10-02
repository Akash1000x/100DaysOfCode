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

// approach 1

// void sort(Node* &head){
//     int zero = 0;
//     int one = 0;
//     int two = 0;

//     Node* temp = head;

//     while(temp != NULL){
//         if(temp->data == 0){
//             zero++;
//         }
//         else if(temp->data == 1){
//             one++;
//         }
//         else{
//             two++;
//         }
//         temp = temp->next;
//     }

//     Node* temp2 = head;

//     while(temp2 != NULL){
//         if(zero > 0){
//             temp2->data = 0;
//             zero--;
//         }
//         else if (one > 0){
//             temp2->data = 1;
//             one--;
//         }
//         else if(two > 0){
//             temp2->data = 2;
//             two--;
//         }
//         temp2 = temp2->next;
//     }
    
// }

//approach 2 Dummy nodes
Node* sort2(Node* &head){

    //if linked list is empty or has only one node
    if(head == NULL || head->next == NULL){
        //if linked list is empty or has only one node
        return head;
    }
    //creation of dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //traverse the linked list
    Node* curr = head;
    while(curr != NULL){

        if(curr->data == 0){
            //seperating the node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //append the zero node
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1){
            //seperating the node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //append the one node
            oneTail->next = temp;
            oneTail = temp;
        }
        else if(curr->data == 2){
            //seperating the node
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            //append the two node
            twoTail->next = temp;
            twoTail = temp;
        }
    }
    

    // Join them and delete dummy nodes

    //Delete the extra (-1) dummy node
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    //Delete the extra (-1) dummy node
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //Join the three lists
    if (oneHead != NULL){

        //oneHead Linked List is non-empty
        zeroTail->next = oneHead;
        if(twoHead != NULL){
            //twoHead Linked List is non-empty
            oneTail->next = twoHead;
        }
    }
    else{
        //oneHead Linked List is empty
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }


    // Delete the extra (-1) dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;
    //return the head of the sorted linked list
    return zeroHead;
    

    //after 100th line other approach


    // if(zeroHead->next != NULL){
    //     head = zeroHead->next;
    //     if(oneHead->next != NULL){
    //         zeroTail->next = oneHead->next;
    //         if(twoHead->next != NULL){
    //             oneTail->next = twoHead->next;
    //         }
    //     }
    //     else{
    //         if(twoHead->next != NULL){
    //             zeroTail->next = twoHead->next;
    //         }
    //     }
    // }
    // else{
    //     if(oneHead->next != NULL){
    //         head = oneHead->next;
    //         if(twoHead->next != NULL){
    //             oneTail->next = twoHead->next;
    //         }
    //     }
    //     else{
    //         if(twoHead->next != NULL){
    //             head = twoHead->next;
    //         }
    //         else{
    //             head = NULL;
    //         }
    //     }
    // }
    // return head;

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
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(0);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    Node* head = first;
    Node* tail = sixth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;



    cout<<"Before:"<<endl;
    print(head);
    cout<<endl;

    //approach 1
    // sort(head);
    
    //approach 2(beter approach)
    head = sort2(head);


    cout<<"After reverse:"<<endl;
    print(head);
    return 0;
}