//question link: https://leetcode.com/problems/copy-list-with-random-pointer/



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//using map 
Node* solve(Node* head,unordered_map<Node*,Node*> &mp){
    if(head == NULL) return 0;

    Node* newHead = new Node(head->val);
    mp[head] = newHead;
    newHead->next = solve(head->next,mp);
    if(head->random){
        // Node *ar = head->random;
        newHead->random = mp[head->random];
    }
    return newHead;
}


class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*,Node*>mp;
       return solve(head,mp);
       
    }
};


//without using map



class Solution {
public:
    Node* copyRandomList(Node* head) {
 
    if(!head) return 0;

    Node* it = head;
    while(it){
        Node* clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    it = head;
    while(it){
        Node* clonedNode = it->next;
        clonedNode->random = it->random ? it->random->next : NULL;
        it = it->next ->next;
    }
    

    it = head;
    Node* cloneHead = it->next;
    while(it){
        Node* clonedNode = it->next;
        it->next = it->next->next;
        if(clonedNode->next){
            clonedNode->next = clonedNode->next->next;
        }
        it = it->next;
    }
    return cloneHead;
    }
};