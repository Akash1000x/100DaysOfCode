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
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

   ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* mergList = new ListNode(-1);
        ListNode* temp = mergList;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        // If one of the lists is not empty, append its remaining nodes
        if(list1 != NULL){
            temp->next = list1;
        }
        if(list2 != NULL){
            temp->next = list2;
        }
        return mergList->next;
    }

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;

        // Find the middle of the list
        ListNode* mid = findMid(head);

        // Divide the list into two halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        // Sort the two halves
        
        left = sortList(left);
    
        right = sortList(right);
        
        // Merge the two sorted lists
        ListNode* mergeList = merge(left,right);
        // Return the head of the merged list
        return mergeList;
    }
};