class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(head == NULL || M==0 || N == 0) return ;
        int i = M;
        int j = N;
        struct Node* temp = head;
        struct Node* prev = NULL;
        while(temp != NULL){
            
            if(i > 0 && j>0){
                prev = temp;
                temp = temp->next;
                i--;
            }
            else if(i == 0 && j > 0){
                Node* d = temp->next;
                delete temp;
                temp = d;
                j--;
            }
            else{
                prev->next = temp;
                i = M;
                j = N;
            }
            
        }
        //we have to delete the last N nodes
        prev->next = NULL;  
    }
};
