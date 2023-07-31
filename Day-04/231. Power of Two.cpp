class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // if(n==1 ){
        //     return true;
        // }
        // else if(n==0){
        //     return false;
        // }
       int i=0; 
       while(i<32){
           
            if(pow(2,i)==n){
                return true;
            }
            i++;
       }
        return false;
    }
};
