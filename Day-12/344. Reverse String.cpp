class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i = 0;
        int e = (s.size()-1);

        while( i < e ){

            swap(s[i++],s[e--]);

        }
    }
};


//or single line code solution is

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        reverse(s.begin(),s.end());
    }
};