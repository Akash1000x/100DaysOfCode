

// Given a pointer to the head of a linked list and a specific position, determine the data value at that position. Count backwards from the tail node. The tail is at postion 0, its parent is at 1 and so on.
// Example
//   head refers to the linked list 1 -> 2 -> 3 -> 4 -> NULL
//   positionFromTail = 2
//   The data value  is 2, the third element from the tail of the list.


void solve(SinglyLinkedListNode* &head, int &positionFromTail,int &ans){
    if(head == NULL) return;
    
    solve(head->next,positionFromTail,ans);
    
    if(positionFromTail == 0){
        ans = head->data;
    }
    positionFromTail--;
    
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int ans = -1;
    solve(llist,positionFromTail,ans);
    return ans;
}


