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

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = curr->next;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = reverse(l1);
        ListNode* list2 = reverse(l2);

        //creating a new Linked List
        ListNode* dummy = NULL;
        int carry = 0;
        while(list1 != NULL || list2 != NULL || carry > 0){
            int sum = carry;
            if(list1 != NULL){
                sum += list1->val;
                list1 = list1->next;
            }
            if(list2 != NULL){
                sum += list2->val;
                list2 = list2->next;
            }
            carry = sum/10;

            ListNode* newNode = new ListNode(sum%10);
            newNode->next = dummy;
            dummy = newNode;            
        }
        return dummy;
    }
};





//simple understanding of the above code

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head){
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         ListNode* next=NULL;

//         while(curr!=NULL){
//             next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }

//         return prev;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head1=reverseList(l1);
//         ListNode* head2=reverseList(l2);

//         ListNode* temp=new ListNode(0);
//         ListNode* kemp=temp;
//         int carry=0;

//         while(head1!=NULL && head2!=NULL){
//             int value=head1->val+head2->val+carry;
//             carry=value/10;
//             temp->next=new ListNode(value%10);
//             head1=head1->next;
//             head2=head2->next;
//             temp=temp->next;
//         }

//         while(head1!=NULL){
//             int value=head1->val+carry;
//             carry=value/10;
//             temp->next=new ListNode(value%10);
//             head1=head1->next;
//             temp=temp->next;
//         }

//         while(head2!=NULL){
//             int value=head2->val+carry;
//             carry=value/10;
//             temp->next=new ListNode(value%10);
//             head2=head2->next;
//             temp=temp->next;
//         }

//         if(carry!=0){
//             temp->next=new ListNode(carry);
//         }

//         ListNode* ans=reverseList(kemp->next);
//         return ans;

//     }
// };