#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool palindromCheck(Node* &head){

    if(head == NULL || head->next == NULL){
        return true; // An empty list or a single node list is a palindrome.
    }

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* prev = NULL;
    Node* curr = slow;
    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare the first half with the reversed second half
    Node* firstHalf = head;
    Node* secondHalf = prev;
    while(secondHalf != NULL){
        if(firstHalf->data != secondHalf->data){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}



int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);
    Node* head = first;
    Node* tail = sixth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;


    bool check = palindromCheck(head);
    if(check == 1){
        cout<<"ll is palindrome"<<endl;
    }
    else{
        cout<<"ll is not palindrome"<<endl;
    }   
    




    return 0;
}


//leetcode solution

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    
    if( head->next == NULL){
        return true;
    }
    ListNode* temp = head;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast!= NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    // return slow;

    ListNode* prev = NULL;
    ListNode* curr = slow->next;
    ListNode* forward = curr->next;
    while(curr != NULL){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    // return prev;

    slow->next = prev;

    while(prev != NULL){
        if(temp->val != prev->val){
            return false;
        }
        temp = temp->next;
        prev = prev->next;
    }
    return true;
    }
};
*/