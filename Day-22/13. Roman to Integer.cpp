class Solution {
public:
    unordered_map<char,int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int romanToInt(string s) {

    int ans = 0;

    for(int i = 0;i<s.size();i++){

        if(i<s.size()-1 && mp[s[i]] < mp[s[i+1]]){

            ans += mp[s[i+1]] - mp[s[i]];
            i++;
        }
        else{
            ans += mp[s[i]];
        }
        
    }
    return ans;
    }
};

//or


class Solution {
public:
    int romanToInt(string s) {
        int out = 0;
        for(int i = 0; i< s.size(); i++){
            switch (s[i])
            {
                case 'I':

                    if(s[i+1] == 'V'){
                        out = out + 4;
                        i++;
                    }else if(s[i+1] == 'X'){
                        out = out + 9;
                        i ++;
                    }else{
                        out = out + 1;
                    }
                    break;
                case 'V':
                    out = out+5;
                    break;
                case 'X':
                    if(s[i+1] == 'L'){
                        out = out + 40;
                        i++;
                    }else if(s[i+1] == 'C'){
                        out = out + 90;
                        i ++;
                    }else{
                        out = out + 10;
                    }

                    break;
                case 'L':
                    out = out+ 50;
                    break;
                case 'C':
                    if(s[i+1] == 'D'){
                        out = out + 400;
                        i ++;
                    }else if(s[i+1] == 'M'){
                        out = out + 900;
                        i++;
                    }else{
                        out = out + 100;
                    }

                    break;
                case 'D':
                    out =  out+ 500;
                    break;
                case 'M':
                    out = out+ 1000;
                    break;
            }
        }
        return out;
    }
};