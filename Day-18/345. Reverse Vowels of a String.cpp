class Solution {
    
public:

    string reverseVowels(string s) {

        string vowels = {"aeiouAEIOU"}; 

        int i = 0;
        int e = s.size()-1;

        while(i<e){
            if(vowels.find(s[i]) != string::npos && vowels.find(s[e]) != string::npos){
                swap(s[i],s[e]);
                i++;
                e--;
            }

            else if( vowels.find(s[i]) == string::npos){
                i++;
            }
            else{
                e--;
            }

        }
        return s;
    }
};



//or


class Solution {
public:
    string reverseVowels(string s) {

        string word = s;
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";
        

        while (start < end) {

            while (start < end && vowels.find(word[start]) == string::npos) {
                start++;
            }

            while (start < end && vowels.find(word[end]) == string::npos) {
                end--;
            }
            swap(word[start], word[end]);

            start++;
            end--;
        }
        return word;
    }
};