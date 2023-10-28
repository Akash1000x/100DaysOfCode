class Solution {
public:
    int firstUniqChar(string s) {
        //using queue
        
        // queue<int> q;
        // vector<int> arr(26,0);
		    
		// for(int i= 0;i<s.size();i++){
		        
        //     arr[s[i]-'a']++;
            
        //     q.push(i); 
		// }

        // while(!q.empty()){
        //     int index = s[q.front()];

        //     if(arr[index -'a' ] > 1){
        //         q.pop();
        //     }
        //     else{
        //         return q.front();
                
        //     }
        // }
	    // return -1;

        
        vector<int> arr(26,0);
        for (auto& ch : s)
            arr[ch -'a']++;

        for (int i = 0; i < s.size(); ++i)
            if (arr[s[i] -'a'] == 1)
                return i;
        
        return -1;
    }
};