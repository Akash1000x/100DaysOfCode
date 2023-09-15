class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26] = {0};
        for(int i = 0;i<s.size();i++){
            int n = s[i] - 'a' ;
            arr1[n]++;
        }

        int arr2[26] = {0};
        for(int i = 0;i<t.size();i++){
            int n = t[i] -'a' ;
            arr2[n]++;
        }

        for(int i = 0;i<26;i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        
        return true;
    }
};