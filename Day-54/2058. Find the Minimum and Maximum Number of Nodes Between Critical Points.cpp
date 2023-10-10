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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        ans[0] = -1;
        ans[1] = -1;
        if(head == NULL || head->next == NULL || head->next->next==NULL || head->next->next->next == NULL){
            return ans;
        }

        ListNode* left = head;
        ListNode* curr = head->next;
        ListNode* right = head->next->next;

        int minDist = INT_MAX;
        int firstCp = -1;
        int lastCp = -1;
        int i = 1;

        while(right){
            if((curr->val > left->val && curr->val > right->val) || 
                        ( curr->val < left->val && curr->val < right->val)){

                if(firstCp == -1){
                    firstCp = i;
                    lastCp = i;
                }
                else{
                    minDist = min(minDist,i-lastCp);
                    lastCp = i;
                }
                
            }
            i++;
            left= left->next;
            curr = curr->next;
            right = right->next;
           

        }

        if(firstCp == lastCp){
            return ans;
        }
        else{
            ans[0] = minDist;
            ans[1] = lastCp - firstCp;
        }
        return ans;
    }
    
};