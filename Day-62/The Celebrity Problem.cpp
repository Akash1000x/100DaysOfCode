class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int celebriti = 0;
        
        for(int i=1;i<n;i++){
            if(M[celebriti][i] == 1){
                celebriti = i;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(i != celebriti && (M[celebriti][i] == 1  || M[i][celebriti] == 0)){
                return -1;
            }
        }
        return 1;
    }
};



//or

// class Solution 
// {
//     public:
//     //Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& M, int n) 
//     {  
//         stack<int> st;
        
//         for(int i = 0;i<n;i++){
//             st.push(i);
//         }
        
//         while(st.size() != 1){
//             int a = st.top(); st.pop();
//             int b = st.top(); st.pop();
            
//             if(M[a][b] == 0 ){
//                 st.push(b);
//             }
//             else{
//                 st.push(a);
//             }
//         }
//         int mightBeCelebrity = st.top();
        
//         for(int i = 0;i<n;i++){
//             if(i != mightBeCelebrity && (M[mightBeCelebrity][i] == 1 || M[i][mightBeCelebrity]==0)){
//                 return -1;
//             }
//         }
//         return 1;
        
//     }
// };