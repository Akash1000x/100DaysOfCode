//minimum bracket reversal problem


int countRev (string s)
{
    //if the size of string is odd.
    if(s.size() %2 != 0) return -1;
    
    stack<char> st;
    
    for(auto ch:s){
        
        if(ch == '}'){
            if(!st.empty() && st.top()=='{'){ 
                st.pop();
            } 
            else{
                st.push(ch);
            }
        }
        else{
            st.push(ch);
        }
    }
    
    int cnt = 0;
    
    while(!st.empty()){
        if(st.top() == '}'){
            st.pop();
        
            if(st.top() == '{'){
                st.pop();
            }
            else{
                cnt++;
                st.pop();
            }
        }
        else{
            cnt++;
            st.pop();
           
            if(st.top() == '{'){
                st.pop();
            }
            else{
                cnt++;
                st.pop();
            }
           
        }
    }

   //or 


    // while(!st.empty()){
    //     char a= st.top();
    //     st.pop();
    //     char b = st.top(); st.pop();
    //     if(a == b){
    //         cnt++;
    //     }
    //     else{
    //         cnt +=2;
    //     }
    // }
    
    return cnt;
    
    
}