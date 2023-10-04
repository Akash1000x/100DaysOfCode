#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;


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
    

    // Recursive Solution
    // ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    //     if(list1 == NULL) return list2;
    //     if(list2 == NULL) return list1;

    //     ListNode* ans = NULL;
    //     if(list1->val <= list2->val){
    //         ans = list1;
    //         ans ->next = mergeTwoLists(list1->next,list2);
    //     }
    //     else{
    //         ans = list2;
    //         ans->next = mergeTwoLists(list1,list2->next);
    //     }
    //     return ans;
    // }
    
};

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution s;
    ListNode* mergedList = s.mergeTwoLists(list1, list2);

    // ListNode* mergedList = s.mergeTwoLists2(list1, list2);


    while(mergedList != NULL){
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}