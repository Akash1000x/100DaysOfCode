void lowercase(string &s){
   
    for (int i = 0;i<=s.size()-1;i++){

        if(s[i] >='A' && s[i]<= 'Z'){
            
            s[i] = tolower(s[i]);
        }
    }
}

class Solution {
public:
    bool isPalindrome(string s) {

        lowercase(s);

        int i = 0;

        int e = s.size()-1;

        while(i<e){

            if(isalnum(s[i])==0){
                i++;
            }

            else if(isalnum(s[e])==0){
                e--;
            }

            else if(s[i] != s[e]){
                return false;
            } 
            
            else {
                i++;
                e--;
            }
        }

        return true;
    }
};