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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;  
        
       
        while(head != NULL){
            ll.push_back(head->val);
            head= head->next;
        }

        stack<int> st; 
        vector<int> ans(ll.size(),0); 

        st.push(0);
        // Iterate through the vector in reverse order to find the next larger elements.
        for(int i = ll.size()-1; i >= 0; i--){
          
          // While the stack is not empty and the current element is larger or equal to the element at the top of the stack.
          while(st.top() <= ll[i] ){
            if(st.top() == 0){
                ans[i] = 0; // If the stack top is 0, set the result to 0.
                break;
            }
            else{
                st.pop(); // Pop elements from the stack until the current element is larger.
            }
          }
          ans[i] = st.top(); // Set the result for the current index to the value at the top of the stack.
          st.push(ll[i]); // Push the current element to the stack for future comparisons.
        }

        //or 
        
        // for(int i = 0;i<ll.size();i++){
        //     //means, ith element is the next greter of the element index present in the stack
        //     while(!st.empty() && ll[i] > ll[st.top()]){
        //         ans[st.top()] = ll[i];
        //         st.pop(); 
        //     }
        //     st.push(i);
        // }

        return ans; // Return the vector containing the next larger elements.
    }
};
