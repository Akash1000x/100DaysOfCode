#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//next smaller element
vector<int> prevSmaller(vector<int> &v){
    vector<int> ans(v.size());
    stack<int> st;
    st.push(-1);
    
    for(int i =0;i<v.size();i++){

        while(st.top()>=v[i]){
            st.pop();
        }

        ans[i] = st.top();
        st.push(v[i]);
        
    }
    return ans;
}

//next smaller element
vector<int> nextSmaller(vector<int> &v){

    vector<int> ans(v.size());
    stack<int> st;
    st.push(-1);
    
    for(int i =v.size()-1;i>=0;i--){

        while(st.top()>=v[i]){
            st.pop();
        }

        ans[i] = st.top();
        st.push(v[i]);
        
    }
    return ans;
}

int main()
{
    vector<int> v{2, 1, 4, 3};

    //next smaller element
    vector<int> ans1 = nextSmaller(v);
    
    cout<<"next smaller element"<<endl;
    for(int i = 0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }cout<<endl;

    //prev smaller element
    vector<int> ans2 = prevSmaller(v);
    
    cout<<"prev smaller element"<<endl;
    for(int i = 0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}