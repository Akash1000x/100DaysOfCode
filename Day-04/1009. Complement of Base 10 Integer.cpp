class Solution {
public:
    int bitwiseComplement(int n) {
        // int ans=0,i=0;
        if(n==0){
            return 1;
        }
        // while(n!=0){
        //     int bit = n%2;
        //     if(bit==0){
        //         bit=1;
        //     }
        //     else{
        //         bit=0;
        //     }
        //     ans = bit * pow(2,i) + ans;
        //     i++;
        //     n = n/2;

        int m=n;
        int mask=0;
        while(m!=0){
            mask = (mask<<1) | 1;
            m = m>>1; 
        }
        int ans = (~n) & mask;
        
        return ans;
        
    }
};