class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
        if((('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')) && (('a'<=s[j]&&s[j]<='z')|| ('A'<=s[j]&&s[j]<='Z'))){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if((s[i]<'A'||s[i]>'z')||(s[i]>'Z'&&s[i]<'a')){
            i++;
        }
        else{
            j--;
          }
        }
        return s;
    }
};