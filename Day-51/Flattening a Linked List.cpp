//gfg important question
//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

//example
// 5 -> 10 -> 19 -> 28 -> NULL
// |    |     |     |
// 7    20    22    35
// |          |     |
// 8          50    40
// |                |
// 30               45

// Output: 5->7->8->10->19->22->28->30->50



/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/



Node* mergeTwoLists(Node* l1,Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    Node* ans = 0;
    if(l1->data <= l2->data){
        ans = l1;
        ans->bottom = mergeTwoLists(l1->bottom,l2);
    }
    else{
        ans = l2;
        ans->bottom = mergeTwoLists(l1,l2->bottom);
    }
    
    return ans;
    
}


Node *flatten(Node *root)
{   
   
   if(!root){
       return 0;
   }
   
   Node* merge =  mergeTwoLists(root,flatten(root->next));
   return merge;
   
}
