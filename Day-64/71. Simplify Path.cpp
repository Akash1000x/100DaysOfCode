class Solution {
    //reversing  stack
    void buildans(stack<string> &s,string &ans){
        if(s.empty()){
            return;
        }

        string minipath = s.top(); s.pop();

        buildans(s,ans);

        ans += minipath;
    }
public:

    string simplifyPath(string path) {
        stack<string> s;
        int n = path.size();
        int i = 0;
        while(i < n){
            int start = i;
            int end = i+1;
            // Find the end of the current part
            while(end < n && path[end] != '/'){
                end++;
            } 
            //extract the current part
            string minipath = path.substr(start,end-start);

            i = end;//update index
            
             // Skip unnecessary path parts
            if(minipath == "/." || minipath == "/"){
                continue;
            }

            if(minipath != "/.."){
                s.push(minipath);
            }
            else if(!s.empty()){
                s.pop();
            }
            
        }
        string ans= s.empty() ? "/" : "";
        // string ans;
        // if(s.empty()){
        //     return "/";
        // }
        // else{
        //     ans = "";
        // }
        buildans(s,ans);
        return ans;
    }
};