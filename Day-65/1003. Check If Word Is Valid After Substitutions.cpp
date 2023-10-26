class Solution {
public:
    bool isValid(string s) {
        // stack<char> st;
        // int i = 0;
        // while(i<=s.size()){
        //     if(st.size() >= 3){
        //         char l = st.top();  st.pop();
        //         char m = st.top();  st.pop();
        //         char n = st.top();  st.pop();

        //         string check = string(1, n)+string(1, m)+string(1, l)  ;
        //         if("abc" != check){
        //             st.push(n);
        //             st.push(m);
        //             st.push(l);
        //         }
        //     }
        //     if(i < s.size()) st.push(s[i]);
        //     i++;
            
        // }
        // if(st.empty()){
        //     return true;
        // }else{
        //     return false;
        // }

        if(s[0] == 'b' || s[0] == 'c'){
            return false;
        }
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i] ==  'a'){
                st.push(s[i]);
            }
            else if(s[i] == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.push(s[i]);
                }
                else{
                    return false;
                }
            }
            else{
                //s[i] =='c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }   
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();

    }
};