class Solution {
public:
    vector<pair<int,string>> mp{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},{50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string intToRoman(int num) {
        string ans ="";

        for(auto it:mp){
            while(num>=it.first){
                ans = ans + it.second;
                num = num - it.first;
            }
            if (num == 0) {
                break;
            }
        }
        return ans;
    }
};


//or


string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10,9,5,4,1};

    // string ans="";

    //     for(int i=0;i<13; i++) {

    //         while (num>=values[i]){ 
    //                 ans +=romanSymbols[i];

    //                 num -=values[i];

    //         }

    //     }

    //     return ans;