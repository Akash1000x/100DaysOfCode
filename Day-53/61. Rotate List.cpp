/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 int findLength(ListNode* &head){
    int len = 0;
    ListNode* temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
  
    return len;  
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int length = findLength(head);

        //actual rotation
        k = k%length;
        //if k is 0 then no need to rotate
        if(k == 0){
            return head;
        }
        //convert to circular linked list 
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = head;

        //find the new head and tail
       
        k = length - k;
        
        //break the circular linked list
        while(k){
            head = head->next;
            tail = tail->next;
            k--;
        }
        tail->next = NULL;
        return head;

        
       
    }
};