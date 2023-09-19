class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[256] = {0};
        bool check[256] = {0};
        for(int i = 0;i<s.size();i++){
            if(map[s[i]] == 0 && check[t[i]] == false){
                map[s[i]] = t[i];
                check[t[i]] = true; 
            }

            if(char(map[s[i]]) != t[i]){
                return false;
            }
        }

        return true;
    }
};