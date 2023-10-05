/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//calculate the length of both the linked list
int size(ListNode *head){
    int i = 0;
    while(head != NULL ){
        head = head->next;
        i++;
    }
    cout<<i<<endl;
    return i;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            //     ListNode* a = headA;
        //     ListNode* b = headB;


        //     while(a->next!=0 && b->next!=0){

        //         if(a==b){
        //             return a;
        //         }

        //         a = a->next;
        //         b = b->next;

        //     }

        //     while(a->next==0){
        //         int blen = 0;

        //         while(b->next== 0){
        //             blen++;
        //             b = b->next;
        //         }

        //         while(blen--){
        //             headB = headB->next;
        //         }
        //     }
        //     while(b->next==0){
        //         int alen = 0;

        //         while(a->next==0){
        //             alen++;
        //             a = a->next;
        //         }

        //         while(alen--){
        //             headA = headA->next;
        //         }
        //     }

        //     while(headA!=headB){
        //         headA = headA->next;
        //         headB = headB->next;
        //     }

        //     return headA;


        // }

        if(headA == NULL || headB == NULL) return NULL;
        
        int len1 = size(headA);
        int len2 = size(headB);

        //diff is the difference between the length of the linked list
        int diff = 0;
        if(len1 >= len2){
            diff = len1 -len2;
            //move the head of the longer linked list by diff
            while(diff != 0){
                headA = headA->next;
                diff--;
            }
        }
        else{
            diff = len2-len1;
            //move the head of the longer linked list by diff
            while(diff != 0){
                headB = headB->next;
                diff--;
            }
        }
        
        //now both the linked list are of same length
        while(headA != NULL && headB != NULL){
            //if the address of the node is same then return the node
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;


    }
};